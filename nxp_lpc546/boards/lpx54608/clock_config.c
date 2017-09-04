/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_common.h"
#include "clock_config.h"
#include "fsl_power.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* System clock frequency. */
extern uint32_t SystemCoreClock;

/*******************************************************************************
 * Code
 ******************************************************************************/

void BOARD_BootClockVLPR(void)
{
    POWER_DisablePD(kPDRUNCFG_PD_FRO_EN); /*!< Ensure FRO is on so that we can switch to its 12MHz mode temporarily*/
    CLOCK_AttachClk(kFRO12M_to_MAIN_CLK); /*!< Switch to 12MHz */
    CLOCK_SetupFROClocking(12000000);     /*!< Turn off high speed output of FRO */
    CLOCK_SetFLASHAccessCyclesForFreq(12000000); /*!< Set FLASH waitstates for core */
    POWER_SetVoltageForFreq(12000000);           /*!< Set voltage for core */
    SystemCoreClock = 12000000;                  /*!< Update information about frequency */
}

void BOARD_BootClockRUN(void)
{
    POWER_DisablePD(kPDRUNCFG_PD_FRO_EN); /*!< Ensure FRO is on so that we can switch to its 12MHz mode temporarily*/
    CLOCK_AttachClk(
        kFRO12M_to_MAIN_CLK);          /*!< Switch to 12MHz first to ensure we can change voltage without accidentally
                                       being below the voltage for current speed */
    POWER_SetVoltageForFreq(48000000); /*!< Set voltage for core */
    CLOCK_SetFLASHAccessCyclesForFreq(48000000); /*!< Set FLASH waitstates for core */
    CLOCK_SetupFROClocking(48000000);            /*!< Setup CPU to run off FRO 48MHz output*/
    CLOCK_AttachClk(kFRO_HF_to_MAIN_CLK);        /*!< Switch main clock to 48MHz */
    SystemCoreClock = 48000000;                  /*!< Update information about frequency */
}

void BOARD_BootClockHSRUN(void)
{
    POWER_DisablePD(kPDRUNCFG_PD_FRO_EN); /*!< Ensure FRO is on so that we can switch to its 12MHz mode temporarily*/
    CLOCK_AttachClk(
        kFRO12M_to_MAIN_CLK);          /*!< Switch to 12MHz first to ensure we can change voltage without accidentally
                                       being below the voltage for current speed */
    POWER_SetVoltageForFreq(96000000); /*!< Set voltage for core */
    CLOCK_SetFLASHAccessCyclesForFreq(96000000); /*!< Set FLASH waitstates for core */
    CLOCK_SetupFROClocking(96000000);            /*!< Setup CPU to run off FRO 96MHz output*/
    CLOCK_AttachClk(kFRO_HF_to_MAIN_CLK);        /*!< Switch main clock to 96MHz */
    SystemCoreClock = 96000000;                  /*!< Update information about frequency */
}

void BOARD_BootClock180M(void)
{
    /*!< Set up the clock sources */
    /*!< Set up FRO */
    POWER_DisablePD(kPDRUNCFG_PD_FRO_EN);                   /*!< Ensure FRO is on  */
    CLOCK_AttachClk(kFRO12M_to_MAIN_CLK);                  /*!< Switch to FRO 12MHz first to ensure we can change voltage without accidentally
                                                                being below the voltage for current speed */
    POWER_SetVoltageForFreq(180000000U);             /*!< Set voltage for the one of the fastest clock outputs: System clock output */
    CLOCK_SetFLASHAccessCyclesForFreq(180000000U);    /*!< Set FLASH wait states for core */

    /*!< Set up SYS PLL */
    const pll_setup_t pllSetup = {
        .pllctrl =  SYSCON_SYSPLLCTRL_SELI(32U) | SYSCON_SYSPLLCTRL_SELP(16U) | SYSCON_SYSPLLCTRL_SELR(0U),
        .pllmdec = (SYSCON_SYSPLLMDEC_MDEC(8191U)),
        .pllndec = (SYSCON_SYSPLLNDEC_NDEC(770U)),
        .pllpdec = (SYSCON_SYSPLLPDEC_PDEC(98U)),
        .pllRate = 180000000U,
        .flags =  PLL_SETUPFLAG_WAITLOCK | PLL_SETUPFLAG_POWERUP
    };
    
    CLOCK_AttachClk(kFRO12M_to_SYS_PLL);        /*!< Set sys pll clock source*/
    CLOCK_SetPLLFreq(&pllSetup);                     /*!< Configure PLL to the desired value */


    /*!< Set up dividers */
    CLOCK_SetClkDiv(kCLOCK_DivAhbClk, 1U, false);                  /*!< Reset divider counter and set divider to value 1 */

    /*!< Set up clock selectors - Attach clocks to the peripheries */
    CLOCK_AttachClk(kSYS_PLL_to_MAIN_CLK);                  /*!< Switch MAIN_CLK to SYS_PLL */
    SYSCON->MAINCLKSELA = ((SYSCON->MAINCLKSELA & ~SYSCON_MAINCLKSELA_SEL_MASK) | SYSCON_MAINCLKSELA_SEL(3U)); /*!< Switch MAINCLKSELA to FRO_HF even it is not used for MAINCLKSELB */
    /* Set SystemCoreClock variable. */
    SystemCoreClock = 180000000;
} 


