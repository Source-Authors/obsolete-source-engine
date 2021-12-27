//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//

#include "pch_tier0.h"
#include "tier0/platform.h"
#include "tier0/systeminformation.h"

#ifdef IS_WINDOWS_PC 
#include <windows.h>
#include <tchar.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PrivateType( xxx ) ValvePrivateType_##xxx

	typedef enum { SystemPerformanceInformation = 2 }
		PrivateType( SYSTEM_INFORMATION_CLASS );

	typedef LONG PrivateType( NTSTATUS );

	typedef PrivateType( NTSTATUS ) ( WINAPI * PrivateType( NtQuerySystemInformation ) )
		(
		/*IN*/ PrivateType( SYSTEM_INFORMATION_CLASS ) SystemInformationClass,
		/*OUT*/ PVOID SystemInformation,
		/*IN*/ ULONG SystemInformationLength,
		/*OUT*/ PULONG ReturnLength /*OPTIONAL*/
		);

	typedef struct
	{
		LARGE_INTEGER IdleProcessTime;
		LARGE_INTEGER IoTransferCount[3];
		ULONG IoOperationCount[3];
		ULONG AvailablePages;
		ULONG CommittedPages;
		ULONG CommitLimit;
		ULONG u00683;
		ULONG u00684;
		ULONG u00685;
		ULONG u00686;
		ULONG u00687;
		ULONG u00688;
		ULONG u00689;
		ULONG u00690;
		ULONG u00691;
		ULONG u00692;
		ULONG u00693;
		ULONG u00694;
		ULONG u00695;
		ULONG u00696;
		ULONG PagedPoolPages;
		ULONG NonPagedPoolPages;
		ULONG PagedPoolAllocs;
		ULONG PagedPoolFrees;
		ULONG NonPagedPoolAllocs;
		ULONG NonPagedPoolFrees;
		ULONG FreeSystemPtes;
		ULONG u00704;
		ULONG u00705;
		ULONG u00706;
		ULONG NonPagedPoolLookasideHits;
		ULONG PagedPoolLookasideHits;
		ULONG FreePagedPoolPages;
		ULONG u00710;
		ULONG u00711;
		ULONG u00712;
		ULONG uCounters[34];
	}
	PrivateType( SYSTEM_PERFORMANCE_INFORMATION );

#ifdef __cplusplus
}
#endif

//
//	Cached information about a dll proc
//
class CSysCallCacheEntry
{
public:
	CSysCallCacheEntry();
	~CSysCallCacheEntry();

public:
	bool IsInitialized() const;
	SYSTEM_CALL_RESULT_t CallResult() const;

	SYSTEM_CALL_RESULT_t InitializeLoadModule( _TCHAR *pszModule, char *pszFunction );
	SYSTEM_CALL_RESULT_t InitializeFindModule( _TCHAR *pszModule, char *pszFunction );
	SYSTEM_CALL_RESULT_t InitializeFindProc( HMODULE hModule, char *pszFunction );

	void SetFailed( SYSTEM_CALL_RESULT_t eResult );
	void Reset();

	template < typename FN >
	FN GetFunction() const;

protected:
	SYSTEM_CALL_RESULT_t m_eResult;
	FARPROC m_pfnSysCall;
	HMODULE m_hModule;
	bool m_bInitialized;
	bool m_bFreeModule;
};

struct CSysCallCacheEntry_LoadModule : public CSysCallCacheEntry
{
	CSysCallCacheEntry_LoadModule( _TCHAR *pszModule, char *pszFunction ) { InitializeLoadModule( pszModule, pszFunction ); }
};
struct CSysCallCacheEntry_FindModule : public CSysCallCacheEntry
{
	CSysCallCacheEntry_FindModule( _TCHAR *pszModule, char *pszFunction ) { InitializeFindModule( pszModule, pszFunction ); }
};
struct CSysCallCacheEntry_FindProc : public CSysCallCacheEntry
{
	CSysCallCacheEntry_FindProc( HMODULE hModule, char *pszFunction ) { InitializeFindProc( hModule, pszFunction ); }
};



CSysCallCacheEntry::CSysCallCacheEntry() :
	m_eResult( SYSCALL_SUCCESS ),
	m_pfnSysCall( NULL ),
	m_hModule( NULL ),
	m_bInitialized( false ),
	m_bFreeModule( false )
{
}

CSysCallCacheEntry::~CSysCallCacheEntry()
{
	Reset();
}

bool CSysCallCacheEntry::IsInitialized() const
{
	return m_bInitialized;
}

SYSTEM_CALL_RESULT_t CSysCallCacheEntry::CallResult() const
{
	return m_eResult;
}

SYSTEM_CALL_RESULT_t CSysCallCacheEntry::InitializeLoadModule( _TCHAR *pszModule, char *pszFunction )
{
	m_bInitialized = true;

	m_hModule = ::LoadLibrary( pszModule );
	m_bFreeModule = true;
	if ( !m_hModule )
		return m_eResult = SYSCALL_NODLL;

	return InitializeFindProc( m_hModule, pszFunction );
}

SYSTEM_CALL_RESULT_t CSysCallCacheEntry::InitializeFindModule( _TCHAR *pszModule, char *pszFunction )
{
	m_bInitialized = true;

	m_hModule = ::GetModuleHandle( pszModule );
	m_bFreeModule = false;
	if ( !m_hModule )
		return m_eResult = SYSCALL_NODLL;

	return InitializeFindProc( m_hModule, pszFunction );
}

SYSTEM_CALL_RESULT_t CSysCallCacheEntry::InitializeFindProc( HMODULE hModule, char *pszFunction )
{
	m_bInitialized = true;

	m_pfnSysCall = GetProcAddress( hModule, pszFunction );
	if ( !m_pfnSysCall )
		return m_eResult = SYSCALL_NOPROC;

	return m_eResult = SYSCALL_SUCCESS;
}

void CSysCallCacheEntry::Reset()
{
	if ( m_bInitialized )
	{
		if ( m_bFreeModule && m_hModule )
			::FreeLibrary( m_hModule );
		m_eResult = SYSCALL_SUCCESS;
		m_hModule = NULL;
		m_pfnSysCall = NULL;
		m_bFreeModule = false;
		m_bInitialized = false;
	}
}

void CSysCallCacheEntry::SetFailed( SYSTEM_CALL_RESULT_t eResult )
{
	m_eResult = eResult;
}

template < typename FN >
FN CSysCallCacheEntry::GetFunction() const
{
	return reinterpret_cast< FN >( m_pfnSysCall );
}



//
//	Plat_GetMemPageSize
//		Returns the size of a memory page in bytes.
//
unsigned long Plat_GetMemPageSize()
{
	return 4;	// On 32-bit systems memory page size is 4 Kb
}

//
//	Plat_GetPagedPoolInfo
//		Fills in the paged pool info structure if successful.
//
SYSTEM_CALL_RESULT_t Plat_GetPagedPoolInfo( PAGED_POOL_INFO_t *pPPI )
{
	memset( pPPI, 0, sizeof( *pPPI ) );

	return SYSCALL_UNSUPPORTED;
}


#else


//
//	Plat_GetMemPageSize
//		Returns the size of a memory page in bytes.
//
unsigned long Plat_GetMemPageSize()
{
	return 4;	// Assume unknown page size is 4 Kb
}

//
//	Plat_GetPagedPoolInfo
//		Fills in the paged pool info structure if successful.
//
SYSTEM_CALL_RESULT_t Plat_GetPagedPoolInfo( PAGED_POOL_INFO_t *pPPI )
{
	memset( pPPI, 0, sizeof( *pPPI ) );
	return SYSCALL_UNSUPPORTED;
}


#endif