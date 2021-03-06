/*
================================================================================
*             Texas Instruments OMAP(TM) Platform Software
* (c) Copyright Texas Instruments, Incorporated. All Rights Reserved.
*
* Use of this software is controlled by the terms and conditions found
* in the license agreement under which this software has been supplied.
*
================================================================================
*/
//
//  File:  bsp_opp_map.h
//

#ifndef __BSP_OPP_MAP_H
#define __BSP_OPP_MAP_H

#pragma warning (push)
#pragma warning (disable:4200)

#include "bsp_def.h"
#include "am33x_clocks.h"
#include "omap_dvfs.h"

//-----------------------------------------------------------------------------
typedef struct {
    VoltageProcessorSetting_t   vpInfo;
    int                         dpllCount;
    DpllFrequencySetting_t      rgDpllFreqSettings[kDPLL_COUNT];
    int                         dpllClkOutCount;
    DpllClkOutFreqSetting_t     rgDpllClkOutFreqSettings[kDPLL_CLKOUT_COUNT];    
    int                         clkCount;
    clkFreqSetting_t            rgClkFreqSettings[];
} VddOppSetting_t;

#pragma warning (pop)


#define VDD1_OPP_COUNT      AM33x_OPP_NUM
#define VDD2_OPP_COUNT      3

#define INITIAL_VDD2_OPP         (kOpp2)
#define MAX_VDD2_OPP             (kOpp2)
#define MAX_VDD1_OPP             (kOpp5)

static Dvfs_OperatingPoint_e Vdd1_init_val[VDD1_OPP_COUNT + 1]=
{
    kOppUndefined,
    kOpp1,	
    kOpp2,		
    kOpp3,	
    kOpp4,
    kOpp5
};


//-----------------------------------------------------------------------------

// For TPS65917 use the following equation to calculate the value given a volt.
/*	Select VDD1 voltage	
	**	Vout = SEL[5:0] � 25 mV + 900 mV
	**	1.1V = SEL[5:0] � 25 mV + 900 mV
	**  => SEL[5:0] = 00 1000b = 0x08
	*/

// (just a placeholder)
static VddOppSetting_t vdd1Opp0Info = {
    /*vpInfo*/
    {
        kVdd1, 0, 0							// TPS info
    }, 
    /*DPLL*/
    1,
    {										// vdd1 has 1 dpll
       {
            kDPLL_MPU, 0,  0,  0			// dpll_MPU
       }
    },
    /* DPLL CLkOUT*/
    0,
    {{0,0}},
    /* CLOCKS */
    0,
    {{0,0}},
};

// MPU[275Mhz @ 0.95V]
static VddOppSetting_t vdd1Opp1Info = {
    /*vpInfo*/
    {
        kVdd1, 950,   0x02					// TPS info
    }, 
    /*DPLL*/
    1,
    {										// vdd1 has 1 dpll
       {
            kDPLL_MPU, 275, 275, 23			// dpll_MPU
       }
    },
    /* DPLL CLkOUT*/
    0,
    {{0,0}},
    /* CLOCKS */
    0,
    {{0,0}},
};

// MPU[500Mhz @ 1.10V]
static VddOppSetting_t vdd1Opp2Info = {
    /*vpInfo*/
    {
        kVdd1, 1100,   0x08					// TPS info
    }, 
    /*DPLL*/
    1,
    {										// vdd1 has 1 dpll
       {
            kDPLL_MPU, 500, 500, 23			// dpll_MPU
       }
    },
    /* DPLL CLkOUT*/
    0,
    {{0,0}},
    /* CLOCKS */
    0,
    {{0,0}},
};

// MPU[600Mhz @ 1.20V]
static VddOppSetting_t vdd1Opp3Info = {
    /*vpInfo*/
    {
        kVdd1, 1200,   0x0C					// TPS info
    }, 
    /*DPLL*/
    1,
    {										// vdd1 has 1 dpll
       {
            kDPLL_MPU, 600, 600, 23			// dpll_MPU
       }
    },
    /* DPLL CLkOUT*/
    0,
    {{0,0}},
    /* CLOCKS */
    0,
    {{0,0}},
};

// MPU[720Mhz @ 1.275V]
static VddOppSetting_t vdd1Opp4Info = {
    /*vpInfo*/
    {
        kVdd1, 1275,   0x0f					// TPS info
    }, 
    /*DPLL*/
    1,
    {										// vdd1 has 1 dpll
       {
            kDPLL_MPU, 720, 720, 23			// dpll_MPU
       }
    },
    /* DPLL CLkOUT*/
    0,
    {{0,0}},
    /* CLOCKS */
    0,
    {{0,0}},
};

// MPU[1000Mhz @ 1.325V]
static VddOppSetting_t vdd1Opp5Info = {
    /*vpInfo*/
    {
        kVdd1, 1325,   0x11					// TPS info
    }, 
    /*DPLL*/
    1,
    {										// vdd1 has 1 dpll
       {
            kDPLL_MPU, 1000, 1000, 23		// dpll_MPU
       }
    },
    /* DPLL CLkOUT*/
    0,
    {{0,0}},
    /* CLOCKS */
    0,
    {{0,0}},
};



// CORE[@0.95V]
static VddOppSetting_t vdd2Opp1Info = {
    /*vpInfo*/
    {
        kVdd2, 950,   0x01					// TPS info
    }, 
    /*DPLL*/
    3,
    {										// vdd2 has 2 dplls
       {
            kDPLL_CORE, 100, 50, 23			// dpll_CORE
       },
       {
            kDPLL_PER,  96, 96, 23			// dpll_PER
       },
       {
            kDPLL_DDR,  125, 125, 23		// dpll_DDR //for DDR2
       }
    },
    /* DPLL CLkOUT*/
    4,    
    {										// vdd2 has 4 dpll clkout
       {
            kDPLL_CORE_M4, 1				// dpll_core_m4
       },
       {
            kDPLL_CORE_M5, 1				// dpll_core_m5
       },
       {
            kDPLL_PER_M2,  1				// dpll_per_m2
       },       
    },    
    /* CLOCKS */
    1,
    {										// vdd2 has 1 clocks
       {
            kCPSW_50MHZ_CLK, 2				// 50MHz Mac clock
       },
       {
            kCLK_32KHZ_CK, 1				// 32KHz from PER DPLL
       },
    },
};

// CORE[@1.1V]
static VddOppSetting_t vdd2Opp2Info = {
    /*vpInfo*/
    {
        kVdd2, 1100,   0x08					// TPS info
    }, 
    /*DPLL*/
    3,
    {										// vdd2 has 2 dplls
       {
            kDPLL_CORE, 2000, 1000, 23		// dpll_CORE
       },
       {
            kDPLL_PER,  960, 960, 23		// dpll_PER
       },
       {
            kDPLL_DDR,  200, 200, 23		// dpll_PER //for DDR2
       }
    },
    /* DPLL CLkOUT*/
    4,    
    {										// vdd2 has 4 dpll clkout
       {
            kDPLL_CORE_M4, 10				// dpll_core_m4
       },
       {
            kDPLL_CORE_M5, 8				// dpll_core_m5
       },
       {
            kDPLL_PER_M2,  5				// dpll_per_m2
       },       
    },    
    /* CLOCKS */
    1,    
    {										// vdd2 has 1 clocks
       {
            kCPSW_50MHZ_CLK, 5				// 50MHz Mac clock
       },
       {
            kCLK_32KHZ_CK, 0				// 32KHz from PER DPLL
       },
    },
};

// CORE[@1.1V]
static VddOppSetting_t vdd2Opp3Info = {
    /*vpInfo*/
    {
        kVdd2, 1100,   0x08					// TPS info
    }, 
    /*DPLL*/
    3,
    {										// vdd2 has 2 dplls
       {
            kDPLL_CORE, 2000, 1000, 23		// dpll_CORE
       },
       {
            kDPLL_PER,  960, 960, 23		// dpll_PER
       },
       {
            kDPLL_DDR,  400, 400, 23		// dpll_PER //for DDR3
       }
    },
    /* DPLL CLkOUT*/
    4,    
    {										// vdd2 has 4 dpll clkout
       {
            kDPLL_CORE_M4, 10				// dpll_core_m4
       },
       {
            kDPLL_CORE_M5, 8				// dpll_core_m5
       },
       {
            kDPLL_PER_M2,  5				// dpll_per_m2
       },       
    },    
    /* CLOCKS */
    1,    
    {										// vdd2 has 1 clocks
       {
            kCPSW_50MHZ_CLK, 5				// 50MHz Mac clock
       },
       {
            kCLK_32KHZ_CK, 0				// 32KHz from PER DPLL
       },
    },
};

//-----------------------------------------------------------------------------
static VddOppSetting_t  *_rgVdd1OppMap[VDD1_OPP_COUNT] = {
    &vdd1Opp1Info,      // kOpp1
    &vdd1Opp2Info,      // kOpp2
    &vdd1Opp3Info,      // kOpp3
    &vdd1Opp4Info,      // kOpp4
    &vdd1Opp5Info,      // kOpp5
};

static VddOppSetting_t  *_rgVdd2OppMap[VDD2_OPP_COUNT] = {
    &vdd2Opp1Info,      // kOpp1
    &vdd2Opp2Info,      // kOpp2
    &vdd2Opp3Info,      // kOpp3
};

//-----------------------------------------------------------------------------
#endif // __BSP_OPP_MAP_H


