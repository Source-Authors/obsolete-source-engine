//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// Defines the entry point for the application.
//
//===========================================================================//

#ifndef RESLISTGENERATOR_H
#define RESLISTGENERATOR_H

#ifdef _WIN32
#pragma once
#endif

class IResListGenerator
{
public:
  virtual ~IResListGenerator() = 0;

	virtual void Init( char const *pchBaseDir, char const *pchGameDir ) = 0;
	virtual void Shutdown() = 0;
	virtual bool IsActive() = 0;

	virtual void SetupCommandLine() = 0;

	virtual bool ShouldContinue() = 0;
};

IResListGenerator *CreateReslistGenerator();
void DestroyReslistGenerator(IResListGenerator *&gen);

#endif // RESLISTGENERATOR_H

