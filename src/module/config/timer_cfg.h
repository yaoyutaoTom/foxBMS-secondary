/**
 *
 * @copyright &copy; 2010 - 2016, Fraunhofer-Gesellschaft zur Foerderung der angewandten Forschung e.V. All rights reserved.
 *
 * BSD 3-Clause License
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 * 1.  Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * We kindly request you to use one or more of the following phrases to refer to foxBMS in your hardware, software, documentation or advertising materials:
 *
 * &Prime;This product uses parts of foxBMS&reg;&Prime;
 *
 * &Prime;This product includes parts of foxBMS&reg;&Prime;
 *
 * &Prime;This product is derived from foxBMS&reg;&Prime;
 *
 */

/**
 * @file    timer_cfg.h
 * @author  foxBMS Team
 * @date    30.09.2015 (date of creation)
 * @ingroup DRIVERS_CONF
 * @prefix  TIM
 *
 * @brief Headers for the configuration of the peripheral timers.
 *
 * Configuration header file of timer module
 *
 */

#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_


/*================== Includes =============================================*/
#include "general.h"
#include "stm32f4xx.h"

/*================== Macros and Definitions ===============================*/


#define TIM4_PWM_OUT_DEFAULT_FREQUENCY    20000 // [Hz]  100 - 125000


#define TIM4_PWM_OUT_DEFAULT_DUTYCYCLE    50    // [%]   0 - 100


#define TIM4_CLOCK_FREQUENCY              0.4            // in [MHz]
#define TIM4_CLOCK_TICK_DURATION_IN_US    2.5            // according to TIM4_CLOCK_FREQUENCY
#define TIM4_CLOCK_TICK_DURATION_IN_MS    0.0025
#define TIM4_CLOCK_TICK_DURATION_IN_S     0.0000025


#define TIM9_CLOCK_FREQUENCY               0.2     // in [MHz]
#define TIM9_CLOCK_TICK_DURATION_IN_US     5.0     // according to TIM9_CLOCK_FREQUENCY
#define TIM9_CLOCK_TICK_DURATION_IN_MS     0.005
#define TIM9_CLOCK_TICK_DURATION_IN_S      0.000005

/*================== Constant and Variable Definitions ====================*/
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim9;

/*================== Function Prototypes ==================================*/


/*================== Constant and Variable Definitions ====================*/


/*================== Function Prototypes ==================================*/


/*================== Function Implementations =============================*/


#endif /* TIMER_CFG_H_ */
