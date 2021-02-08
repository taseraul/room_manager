//------------------------------------------------------------------
//
// Copyright (c) 1999 - 2009 Tapko Technologies GmbH
//
// PROPRIETARY RIGHTS of Tapko Technologies GmbH are involved
// in the subject matter of this material. All manufacturing,
// reproduction, use, and sales rights pertaining to this subject matter
// are governed by the license agreement. The recipient of this software
// implicitly accepts the terms of the license.
//
// This file is part of the Libraries of Tapko Technologies GmbH
// (e.g. TAPKO EIB/KNX Communication Stack)
//
//------------------------------------------------------------------

#include "project.h"
#include "eib_stk.h"
#include "app.h"
#include EIB_DEVICE_MODEL_APP_H_FILE
//#include "doorbell.h"

#ifndef BITF
  #define BIT0 0x00001
  #define BIT1 0x00002
  #define BIT2 0x00004
  #define BIT3 0x00008
  #define BIT4 0x00010
  #define BIT5 0x00020
  #define BIT6 0x00040
  #define BIT7 0x00080

  #define BIT8 0x00100
  #define BIT9 0x00200
  #define BITA 0x00400
  #define BITB 0x00800
  #define BITC 0x01000
  #define BITD 0x02000
  #define BITE 0x04000
  #define BITF 0x08000
#endif // BITF

//------------------------------------------------------------------
// global RAM variables
//------------------------------------------------------------------

unsigned char oldKey[4], presentKey[4];

unsigned const maskArray[8]  = {BIT0, BIT1, BIT2, BIT3, BIT4, BIT5, BIT6, BIT7}; 

//------------------------------------------------------------------
void SetLed(unsigned char nr, unsigned char val)
{
  BL_Control(KSD_LedList[nr], val);
	// KSD_SetUserLEDval(nr, val);
  // KSD_SwitchUserLED(((unsigned int) val) << nr, maskArray[nr]);
}

//------------------------------------------------------------------
unsigned char GetButton(unsigned char nr) 
{
  return (KSD_GetUserButton()  &  maskArray[nr]) != 0 ;
}

//------------------------------------------------------------------
unsigned char GetObjVal(unsigned char objectNr)
{
  unsigned char tempObjectValue;

  GetObjectValue(objectNr, &tempObjectValue);   // get object value by function 
  return(tempObjectValue);
}

//------------------------------------------------------------------
// Initialization of application
//------------------------------------------------------------------
void APP_Init(void)
{
  unsigned char objCntr;
  unsigned char tempObjectValue = 0;
  KSD_InitUserLED();    // Init the 8 LEDs on EVAL board
  KSD_InitUserButton(); // Init the 4 buttons on EVAL board
  for (objCntr = CO_in0; objCntr <= CO_out3; objCntr++)
  {
    SetObjectValue(objCntr, &tempObjectValue); // initialize the object value
    if (objCntr < CO_out0)
      SetLed(objCntr, GetObjVal(objCntr));
  }
}

//------------------------------------------------------------------
// Main program of application (cyclic called)
//------------------------------------------------------------------
void APP_Main(void)
{
  unsigned char objCntr;
  unsigned char tempObjectValue;

  for (objCntr = CO_in0; objCntr <= CO_in3; objCntr++)
  {
    if (CheckUpdateFlag(objCntr))
       SetLed(objCntr,  GetObjVal(objCntr));
  }

  for (objCntr = CO_out0; objCntr <= CO_out3; objCntr++)
  {
     oldKey[objCntr-CO_out0] = presentKey [objCntr-CO_out0];
     presentKey [objCntr-CO_out0] =   GetButton(objCntr-CO_out0);
     if ((  presentKey [objCntr-CO_out0] != 0) && (oldKey[objCntr-CO_out0] == 0) )
     {
       GetObjectValue(objCntr, &tempObjectValue);   // get object value by function
       tempObjectValue ^= 1;                        // change object value
       SetObjectValue(objCntr, &tempObjectValue);   // set object value by function
       SetTransmitRequest(objCntr);                 // send object
       SetLed(objCntr - CO_out0,  tempObjectValue);
     }
  }
}

//------------------------------------------------------------------
#if SC_APPLICATION_TYPE == SC_APPL_CALL_EVENT

// Event handler for the application
void APP_EventHandler(SC_tEventMask event)
{
  if ((event & SC_EVENT_INIT) != 0)
    APP_Init(); // Initialization of the application
  if ((event & ~SC_EVENT_INIT) != 0)
    APP_Main(); // application main routine

  // enable the next line for cyclic application call
  SC_SendEventAppl(SC_TASK_APP1, SC_EVENT_CYCLE);
}
#endif

//------------------------------------------------------------------
// Save program of application
//------------------------------------------------------------------
void APP_Save(void)
{
}

//------------------------------------------------------------------
// NOTE: in APPHW... the group objects and Parameter may not be valid
//------------------------------------------------------------------
void APPHW_Init(void)
{
}

//------------------------------------------------------------------
void APPHW_Cycle(void)
{
}

#if SC_APPLICATION_TYPE == SC_APPL_CALL_EVENT

// Event handler for hardware part of the application
void APPHW_EventHandler(SC_tEventMask event)
{
  if ((event & SC_EVENT_INIT) != 0)
    APPHW_Init(); // Initialization
  if ((event & ~SC_EVENT_INIT) != 0)
    APPHW_Cycle(); // cycle

  // enable the next line for cyclic application call
  SC_SendEvent(SC_TASK_APPHW, SC_EVENT_CYCLE);
}
#endif

//------------------------------------------------------------------
