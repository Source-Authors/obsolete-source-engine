//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//

// memdbgon must be the last include file in a .cpp file!!!
#include "cbase.h"
#include "utlvector.h"
#include "util.h"
#include "halloween/halloween_gift_spawn_locations.h"
#include "tier0/memdbgon.h"
// -------------------------------------------------------------------------

struct valid_item_pos
{
	float x, y, z;
};

static valid_item_pos kValidPositions_MannManor[] = {
	{ -725.000000, 1362.500000, -639.968750 },
	{ -3137.500000, 1500.000000, -1023.968750 },
	{ -1212.500000, 1187.500000, -959.968750 },
	{ -3150.000000, 1375.000000, -791.968750 },
	{ -2237.500000, 2150.000000, -1015.968750 },
	{ -1837.500000, 2250.000000, -895.968750 },
	{ -1162.500000, 1837.500000, -959.968750 },
	{ -3662.500000, 1212.500000, -1024.431152 },
	{ -912.500000, 3937.500000, -1039.968750 },
	{ -175.000000, 1837.500000, -1007.968750 },
	{ -1575.000000, 1762.500000, -959.968750 },
	{ -1625.000000, 1387.500000, -959.968750 },
	{ -850.000000, 1025.000000, -639.468750 },
	{ -2625.000000, 3750.000000, -1086.180908 },
	{ -450.000000, 1850.000000, -1006.910278 },
	{ -2775.000000, 1425.000000, -1023.968750 },
	{ -2037.500000, 1625.000000, -895.968750 },
	{ -637.500000, 2475.000000, -767.968750 },
	{ -3637.500000, 2862.500000, -903.968750 },
	{ -2812.500000, 1325.000000, -791.968750 },
	{ -1212.500000, 2162.500000, -959.968750 },
	{ -1525.000000, 2662.500000, -895.968750 },
	{ -2837.500000, 2537.500000, -1085.712402 },
	{ -1312.500000, 3787.500000, -1079.968750 },
	{ -2450.000000, 1637.500000, -895.968750 },
	{ -625.000000, 1037.500000, -639.968750 },
	{ -3625.000000, 2587.500000, -903.968750 },
	{ -2800.000000, 3362.500000, -1087.954102 },
	{ -2250.000000, 1625.000000, -895.968750 },
	{ -1775.000000, 2825.000000, -783.968750 },
	{ -3712.500000, 2100.000000, -671.968750 },
	{ -3500.000000, 2100.000000, -863.968750 },
	{ -1400.000000, 3325.000000, -1088.116577 },
	{ -800.000000, 2825.000000, -767.968750 },
	{ -1787.500000, 2575.000000, -767.968750 },
	{ -2962.500000, 3187.500000, -668.908264 },
	{ -1962.500000, 1900.000000, -895.968750 },
	{ -712.500000, 2262.500000, -767.968750 },
	{ -587.500000, 3887.500000, -1099.458862 },
	{ -3737.500000, 2112.500000, -863.968750 },
	{ -3212.500000, 1237.500000, -1023.968750 },
	{ -1325.000000, 3987.500000, -1079.968750 },
	{ -737.500000, 1887.500000, -1007.968750 },
	{ -2837.500000, 2137.500000, -1083.385742 },
	{ -3112.500000, 1137.500000, -791.968750 },
	{ -2275.000000, 3187.500000, -767.968750 },
	{ -1475.000000, 2962.500000, -847.968750 },
	{ -3425.000000, 2137.500000, -671.968750 },
	{ -3450.000000, 2912.500000, -903.968750 },
	{ -1725.000000, 3737.500000, -1050.131104 },
	{ -850.000000, 3237.500000, -1031.956299 },
	{ -2650.000000, 2512.500000, -1085.018555 },
	{ -2487.500000, 2037.500000, -1050.676147 },
	{ -1600.000000, 1175.000000, -959.968750 },
	{ -650.000000, 1937.500000, -743.482178 },
	{ -650.000000, 1775.000000, -692.995728 },
	{ -1012.500000, 1500.000000, -639.968750 },
	{ -3700.000000, 1275.000000, -811.867065 },
	{ -3112.500000, 1600.000000, -791.968750 },
	{ -2950.000000, 1850.000000, -1053.853516 },
	{ -1225.000000, 3475.000000, -1086.870605 },
	{ -1150.000000, 3300.000000, -1070.466187 },
	{ -925.000000, 3425.000000, -1050.419189 },
	{ -650.000000, 3300.000000, -1043.805176 },
	{ -625.000000, 2800.000000, -767.968750 },
	{ -2775.000000, 1650.000000, -1023.968750 },
	{ -3575.000000, 1100.000000, -808.125854 },
	{ -1212.500000, 1425.000000, -959.968750 },
	{ -1737.500000, 3000.000000, -783.968750 },
	{ -1462.500000, 2437.500000, -895.968750 },
	{ -862.500000, 2200.000000, -767.968750 },
	{ -2962.500000, 3550.000000, -671.968750 },
	{ -3462.500000, 2487.500000, -903.968750 },
	{ -1012.500000, 3150.000000, -1048.620605 },
	{ -562.500000, 3725.000000, -1087.434692 },
	{ -2062.500000, 3250.000000, -984.070923 },
	{ -2675.000000, 2112.500000, -1082.104248 },
	{ -2487.500000, 2400.000000, -1051.597046 },
	{ -2037.500000, 3137.500000, -838.662476 },
	{ -3062.500000, 1262.500000, -1023.968750 },
	{ -2887.500000, 2812.500000, -694.111816 },
	{ -2987.500000, 3250.000000, -1086.727539 },
	{ -2812.500000, 3762.500000, -1086.203857 },
	{ -2350.000000, 3537.500000, -1082.763184 },
	{ -2162.500000, 3837.500000, -967.968750 },
	{ -1562.500000, 3312.500000, -1079.254028 },
	{ -1375.000000, 3500.000000, -1085.550903 },
	{ -887.500000, 3700.000000, -1059.968750 },
	{ -2812.500000, 2287.500000, -1081.588135 },
	{ -2687.500000, 2362.500000, -1081.903198 },
	{ -2337.500000, 2412.500000, -1023.968750 },
	{ -1950.000000, 1437.500000, -895.968750 },
	{ -2850.000000, 1112.500000, -872.148926 },
	{ -1350.000000, 1862.500000, -959.968750 },
	{ -1600.000000, 2425.000000, -830.815613 },
	{ -3487.500000, 1262.500000, -809.627197 },
	{ -3475.000000, 1237.500000, -1023.968750 },
	{ -2875.000000, 2787.500000, -1085.673584 },
	{ -3012.500000, 2062.500000, -1073.808105 },
	{ -2550.000000, 3962.500000, -1087.083984 },
	{ -1512.500000, 3812.500000, -1079.644287 },
	{ -1100.000000, 3437.500000, -1073.367554 },
	{ -750.000000, 3562.500000, -1059.989502 },
	{ -850.000000, 2987.500000, -767.968750 },
	{ -575.000000, 2287.500000, -767.968750 },
	{ -1175.000000, 2337.500000, -959.968750 },
	{ -1850.000000, 3175.000000, -916.482300 },
	{ -2675.000000, 1125.000000, -954.482300 },
	{ -1562.500000, 1575.000000, -959.968750 },
	{ -600.000000, 525.000000, -759.968750 },
	{ -2962.500000, 2975.000000, -671.584595 },
	{ -3687.500000, 2275.000000, -751.524414 },
	{ -3437.500000, 2250.000000, -863.968750 },
	{ -2750.000000, 1500.000000, -791.968750 },
	{ -2862.500000, 3025.000000, -1088.080444 },
	{ -2650.000000, 3400.000000, -1086.712158 },
	{ -2037.500000, 3850.000000, -967.968750 },
	{ -2050.000000, 3537.500000, -1039.457031 },
	{ -1262.500000, 3625.000000, -1079.968750 },
	{ -1100.000000, 3725.000000, -1079.968750 },
	{ -1137.500000, 2975.000000, -1064.579102 },
	{ -1100.000000, 2800.000000, -1035.468262 },
	{ -1000.000000, 3300.000000, -1043.383545 },
	{ -900.000000, 3550.000000, -1069.937378 },
	{ -675.000000, 3437.500000, -1038.987061 },
	{ -625.000000, 3162.500000, -1048.860962 },
	{ -2825.000000, 1975.000000, -1071.794189 },
	{ -2875.000000, 1250.000000, -1023.968750 },
	{ -2625.000000, 1950.000000, -1080.477051 },
	{ -2512.500000, 2600.000000, -1060.309570 },
	{ -2675.000000, 1250.000000, -990.329102 },
	{ -1025.000000, 1262.500000, -618.168762 },
	{ -2850.000000, 3175.000000, -1091.269287 },
	{ -2275.000000, 3862.500000, -993.140991 },
	{ -1987.500000, 3650.000000, -1038.143188 },
	{ -1937.500000, 3475.000000, -1009.303223 },
	{ -1625.000000, 3925.000000, -1057.784912 },
	{ -575.000000, 3562.500000, -1064.084229 },
	{ -2450.000000, 3400.000000, -1092.235474 },
	{ -1675.000000, 3537.500000, -1058.036133 },
	{ -1187.500000, 2562.500000, -990.317749 },
	{ -1612.500000, 2975.000000, -815.968750 },
	{ -1175.000000, 4000.000000, -1059.968750 },
	{ -2200.000000, 2425.000000, -1023.968750 },
	{ -2162.500000, 3425.000000, -1036.134521 },
	{ -1450.000000, 2187.500000, -767.968750 },
	{ -1100.000000, 2187.500000, -767.968750 },
};

const float g_flPlayerEyeHeight = 70.0f;

static valid_item_pos kValidPositions_Viaduct[] =
{
	{ -1056.508423, 120.524803,   307.972595f - g_flPlayerEyeHeight },
	{ -1245.718750, -371.585114,  316.206665f - g_flPlayerEyeHeight },
	{ -1755.105469, -602.121094,  211.415222f - g_flPlayerEyeHeight },
	{ -1866.556030, -11.241785,   311.038757f - g_flPlayerEyeHeight },
	{ -1801.210083, 567.631775,   221.211823f - g_flPlayerEyeHeight },
	{ -2254.645996, -501.424133,  323.972595f - g_flPlayerEyeHeight },
	{ -2210.340576, 376.084320,   323.972595f - g_flPlayerEyeHeight },
	{ -1888.754272, 639.861633,   204.341263f - g_flPlayerEyeHeight },
	{ -1903.123413, -641.635986,  203.944336f - g_flPlayerEyeHeight },
	{ -1212.720703, 990.511353,   227.972595f - g_flPlayerEyeHeight },
	{ -1225.367554, -966.919922,  227.972595f - g_flPlayerEyeHeight },
	{ -2486.856934, -1201.215576, 194.879059f - g_flPlayerEyeHeight },
	{ -2568.440674, 1470.992432,  195.961288f - g_flPlayerEyeHeight },
	{ -1681.012573, -1190.597534, 131.972595f - g_flPlayerEyeHeight },
	{ -1668.416504, 1226.122070,  131.972595f - g_flPlayerEyeHeight },
	{ -2459.953125, 394.793518,   323.972595f - g_flPlayerEyeHeight },
	{ -2495.843994, -505.581940,  323.972595f - g_flPlayerEyeHeight },
	{ -1507.193359, -632.548096,  207.798416f - g_flPlayerEyeHeight },
	{ -1515.489746, 637.124756,   207.442322f - g_flPlayerEyeHeight },
	{ -1533.132202, 6.273134,     299.123474f - g_flPlayerEyeHeight },
	{ -1533.132202, 6.273134,     299.123474f - g_flPlayerEyeHeight },
	{ -1533.132202, 6.273134,     299.123474f - g_flPlayerEyeHeight },
	{ -1533.132202, 6.273134,     299.123474f - g_flPlayerEyeHeight },
	{ -1533.132202, 6.273134,     299.123474f - g_flPlayerEyeHeight },
	{ -1533.132202, 6.273134,     299.123474f - g_flPlayerEyeHeight },
	{ -1533.132202, 6.273134,     299.123474f - g_flPlayerEyeHeight },
	{ -1767.763306, -31.788916,   304.332611f - g_flPlayerEyeHeight },
	{ -1314.115601, 1.664654,     304.332611f - g_flPlayerEyeHeight },
};

static valid_item_pos kValidPositions_Lakeside[] =
{
	{ 440.514740,   19.020391,    52.031319f   - g_flPlayerEyeHeight },
	{ -439.044678,  -0.653890,    52.031319f   - g_flPlayerEyeHeight },
	{ 14.226428,    -860.007385,  116.031319f  - g_flPlayerEyeHeight },
	{ 536.307800,   -35.320126,   -110.660393f - g_flPlayerEyeHeight },
	{ -522.902588,  -15.580125,   -107.159370f - g_flPlayerEyeHeight },
	{ -13.246658,   556.848022,   84.031319f   - g_flPlayerEyeHeight },
	{ 199.859665,   -560.373779,  52.031319f   - g_flPlayerEyeHeight },
	{ -206.504196,  -524.416443,  52.031319f   - g_flPlayerEyeHeight },

	{ -572.280029,  -854.871521,  -102.842537f - g_flPlayerEyeHeight },
	{ 570.159973,   -833.295898,  -104.718376f - g_flPlayerEyeHeight },
	{ -10.444493,   -1814.084106, 91.031319f   - g_flPlayerEyeHeight },
	{ -1117.456177, -1821.980591, 81.080040f   - g_flPlayerEyeHeight },
	{ 1122.193481,  -1760.623291, 84.117996f   - g_flPlayerEyeHeight },
	{ 934.447083,   -14.523724,   -153.873962f - g_flPlayerEyeHeight },
	{ -935.006165,  0.899750,     -154.107819f - g_flPlayerEyeHeight },
	{ -831.039368,  1028.812988,  -132.968689f - g_flPlayerEyeHeight },
	{ 838.370667,   1039.730347,  -132.968689f - g_flPlayerEyeHeight },
	{ 330.726898,   -1061.698975, 91.031319f   - g_flPlayerEyeHeight },
	{ -347.198090,  -1074.667480, 91.031319f   - g_flPlayerEyeHeight },
	{ -970.985229,  -1151.937866, -129.290192f - g_flPlayerEyeHeight },
	{ 964.682556,   -1112.505127, -132.963379f - g_flPlayerEyeHeight },
	{ -310.233612,  -548.355957,  -68.615242f  - g_flPlayerEyeHeight },
	{ 310.885254,   -545.554932,  -68.772285f  - g_flPlayerEyeHeight },
};

static valid_item_pos kValidPositions_Hightower[] =
{
	{ 6126.312500,  7590.515137, 435.031311f  - g_flPlayerEyeHeight },
	{ 7961.887207,  7579.561523, -35.332085f  - g_flPlayerEyeHeight },
	{ 6192.0f,      7592.0f,     373.0f,                            },
	{ 7634.951660,  7592.539063, 130.810715f  - g_flPlayerEyeHeight },
	{ 6472.569336,  7593.163086, -149.912628f - g_flPlayerEyeHeight }, // Cayle says to use this one three times
	{ 6472.569336,  7593.163086, -149.912628f - g_flPlayerEyeHeight },
	{ 6472.569336,  7593.163086, -149.912628f - g_flPlayerEyeHeight },
	{ 6333.593750,  7398.845703, 425.031311f  - g_flPlayerEyeHeight },
	{ 6338.365723,  7780.267090, 425.031311f  - g_flPlayerEyeHeight },
	{ 6111.854004,  7582.590820, 425.031311f  - g_flPlayerEyeHeight },
	{ 8269.034180,  8336.364258, -193.885345f - g_flPlayerEyeHeight },
	{ 6152.998047,  6708.033203, -190.968689f - g_flPlayerEyeHeight },
	{ 7947.068359,  7592.274902, -45.030327f  - g_flPlayerEyeHeight },
	{ 8690.697266,  7519.280273, -134.968689f - g_flPlayerEyeHeight },
	{ 5184.807617,  7460.308594, 65.031311f   - g_flPlayerEyeHeight },
	{ 5176.026367,  7762.865234, 65.031311f   - g_flPlayerEyeHeight },
	{ 5665.124512,  7912.830078, 186.027237f  - g_flPlayerEyeHeight },
	{ 5629.083984,  7272.486816, 186.031311f  - g_flPlayerEyeHeight },
	{ 7569.272461,  7356.835938, 30.543331f   - g_flPlayerEyeHeight },
	{ 7620.356445,  7806.569824, 43.632362f   - g_flPlayerEyeHeight },
	{ 10225.334961, 7462.086914, -366.968689f - g_flPlayerEyeHeight },
	{ 10208.725586, 7768.193848, -366.968689f - g_flPlayerEyeHeight },
};

struct halloween_map_info
{
	const char	   *m_pszMapName;
	valid_item_pos *m_pPositions;
	int				m_pPositionCount;
};

static halloween_map_info g_HalloweenMapInfo[] =
{
	{ "cp_manor_event",			kValidPositions_MannManor,	ARRAYSIZE( kValidPositions_MannManor ) },
	{ "koth_viaduct_event",		kValidPositions_Viaduct,	ARRAYSIZE( kValidPositions_Viaduct ) },
	{ "koth_lakeside_event",	kValidPositions_Lakeside,	ARRAYSIZE( kValidPositions_Lakeside ) },
	{ "plr_hightower_event",	kValidPositions_Hightower,	ARRAYSIZE( kValidPositions_Hightower ) },
};

//
void AddHalloweenGiftPositionsForMap( const char *pszMapName, CUtlVector<Vector> &vLocations )
{
	for ( int i = 0; i < ARRAYSIZE( g_HalloweenMapInfo ); i++ )
	{
		if ( FStrEq( pszMapName, g_HalloweenMapInfo[i].m_pszMapName ) )
		{
			for ( int iPoint = 0; iPoint < g_HalloweenMapInfo[i].m_pPositionCount; iPoint++ )
			{
				vLocations.AddToTail( Vector(
					g_HalloweenMapInfo[ i ].m_pPositions[ iPoint ].x,
					g_HalloweenMapInfo[ i ].m_pPositions[ iPoint ].y,
					g_HalloweenMapInfo[ i ].m_pPositions[ iPoint ].z
				) );
			}
			return;
		}
	}
}