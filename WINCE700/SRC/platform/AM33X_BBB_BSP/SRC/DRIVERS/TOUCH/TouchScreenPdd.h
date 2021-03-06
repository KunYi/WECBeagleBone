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

#ifndef __TOUCHPDD_H
#define __TOUCHPDD_H

// undef here since these are already defined.
#undef ZONE_INIT
#undef ZONE_ERROR

#include <tchddsi.h>
#include "am33x_tsc_adc.h"

//------------------------------------------------------------------------------
// Sample rate during polling.
#define DEFAULT_SAMPLE_RATE                 200               // Hz.
#define TOUCHPANEL_SAMPLE_RATE_LOW          DEFAULT_SAMPLE_RATE
#define TOUCHPANEL_SAMPLE_RATE_HIGH         DEFAULT_SAMPLE_RATE
#define DEFAULT_THREAD_PRIORITY             109

#define RK_HARDWARE_DEVICEMAP_TOUCH     (TEXT("HARDWARE\\DEVICEMAP\\TOUCH"))
#define RV_CALIBRATION_DATA             (TEXT("CalibrationData"))

#define CAL_DELTA_RESET             20
#define CAL_HOLD_STEADY_TIME        1500
#define RANGE_MIN                   0
#define RANGE_MAX                   4096

//------------------------------------------------------------------------------
// local data structures
//

typedef struct
{
    BOOL        bInitialized;
	HANDLE		hReadTouchSampleBufferQueue;
    TSCADC_REGS *regs;
    DWORD       nSampleRate;
    DWORD       nInitialSamplesDropped;
    DWORD       PenUpDebounceMS;
    DWORD       dwSysIntr;
    DWORD       dwSamplingTimeOut;
    BOOL        bTerminateIST;
    HANDLE      hTouchPanelEvent;
    DWORD       dwPowerState;
    HANDLE      hIST;
    LONG        nPenIRQ;
    DWORD       dwISTPriority;
}TOUCH_DEVICE;

// Internal functions.
static HRESULT PDDCalibrationThread();
void PDDStartCalibrationThread();

BOOL PDDGetTouchIntPinState( VOID );
BOOL PDDGetTouchData(UINT32 * pxPos, UINT32 * pyPos);
BOOL PDDGetRegistrySettings( PDWORD );
BOOL PDDInitializeHardware(LPCTSTR pszActiveKey );
VOID PDDDeinitializeHardware( VOID );
VOID PDDTouchPanelDisable();
BOOL PDDTouchPanelEnable();
ULONG PDDTouchIST(PVOID   reserved);
void PDDTouchPanelPowerHandler(BOOL boff);

//TCH PDD DDSI functions
extern "C" DWORD WINAPI TchPdd_Init(
    LPCTSTR pszActiveKey,
    TCH_MDD_INTERFACE_INFO* pMddIfc,
    TCH_PDD_INTERFACE_INFO* pPddIfc,
    DWORD hMddContext
    );

void WINAPI TchPdd_Deinit(DWORD hPddContext);
void WINAPI TchPdd_PowerUp(DWORD hPddContext);
void WINAPI TchPdd_PowerDown(DWORD hPddContext);
BOOL WINAPI TchPdd_Ioctl(
    DWORD hPddContext,
    DWORD dwCode,
    PBYTE pBufIn,
    DWORD dwLenIn,
    PBYTE pBufOut,
    DWORD dwLenOut,
    PDWORD pdwActualOut
    );

#endif
