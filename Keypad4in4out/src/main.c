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
// $HeadURL: https://tapko-app.tapko.local:1443/svn/KAIstack/trunk/appl_example/echo/src/main.c $
//
// Project:           EIB-Communication-Stack
//
// $Author: Adler_K $
//
// $Date: 2015-05-06 12:44:24 +0200 (Mi, 06 Mai 2015) $
// $Revision: 1580 $
//------------------------------------------------------------------
#include "project.h"
#include "eib_stk.h"

//------------------------------------------------------------------
void main(void)
{
  hwinit () ;                          // peripheral settings

  WDG_START();
  SC_StackInit();

  while (_TRUE)
  {
    WDG_RESET();

    switch(SC_CyclicCalls())
    {
/*      case SC_SLEEP:
        KAI_LpmSleep();
        break;

      case SC_DEEP_SLEEP:
        KAI_LpmDeepSleep();
        break;*/
    }
  }
}


