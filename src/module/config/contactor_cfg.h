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
 * @file    contactor_cfg.h
 * @author  foxBMS Team
 * @date    23.09.2015
 * @ingroup DRIVERS_CONF
 * @prefix  CONT
 *
 * @brief   Header for the configuration for the driver for the contactors
 *
 * This file defines all needed macros to map the interlock and the contactors'
 * hardware configuration to the software.
 *
 */

#ifndef CONTACTOR_CFG_H_
#define CONTACTOR_CFG_H_

/*================== Includes =============================================*/
#include "general.h"
#include "io_cfg.h"

/*================== Macros and Definitions ===============================*/

/**
 * Use this define as virtual feedback "pin" if a contactor has no
 * feedback pin
 */
#define CONT_HAS_NO_FEEDBACK ((IO_PORTS_e)(0xFF))


#define CONT_HAS_NO_FEEDBACK_SWICHTING_TIME 100


#define CONT_MAXIUMUM_ALLOWED_CONTACTOR_SWITCHING_TIME 100


#define CONT_NUMBER_OF_BAD_COUNTINGS 10


#define BAD_SWITCHOFF_CURRENT_POS 1.0


#define BAD_SWITCHOFF_CURRENT_NEG -1.0


//#define CONT_IGNORE_CONT_INIT_CHECK


/*
 * The number of defines per contactor must be the same as the length
 *  of the array cont_contactors_cfg in contactor_cfg.c
 * Every contactor consists of 1 control pin and 1 feedback pin
 * counting together as 1 contactor.
 * E.g. if you have 1 contactor your define has to be:
 *      #define CONT_INTERLOCK_CONTROL       PIN_MCU_1_INTERLOCK_CONTROL
 *      #define CONT_INTERLOCK_FEEDBACK      PIN_MCU_1_INTERLOCK_FEEDBACK
 */
#define CONT_INTERLOCK_CONTROL                  PIN_MCU_1_INTERLOCK_CONTROL
#define CONT_INTERLOCK_FEEDBACK                 PIN_MCU_1_INTERLOCK_FEEDBACK

/*================== Constant and Variable Definitions ====================*/
/**
 * Symbolic names for contactors' possible states
 */
typedef enum {
    CONT_SWITCH_OFF     = 0,    /*!< Contactor off         --> Contactor is open           */
    CONT_SWITCH_ON      = 1,    /*!< Contactor on          --> Contactor is closed         */
    CONT_SWITCH_UNDEF   = 2,    /*!< Contactor undefined   --> Contactor state not known   */
} CONT_SWITCH_e;

/**
 * Symbolic names for the contactors, which are used in 
 * the contactor_cfg[] array
 */
typedef enum {
    CONT_PLUS_MAIN      = 0,    /*!< Main contactor in the positive path of the powerline      */
    CONT_PLUS_PRECHARGE = 1,    /*!< Precharge contactor in the positive path of the powerline */
    CONT_MINUS_MAIN     = 2,    /*!< Main contactor in the negative path of the powerline      */
} CONT_NAMES_e;

/**
 * Symbolic names defining the electric behavior of the contactor
 */
typedef enum {
    CONT_FEEDBACK_NORMALLY_OPEN     = 0,    /*!< Feedback line of a contactor is normally open      */
    CONT_FEEDBACK_NORMALLY_CLOSED   = 1,    /*!< Feedback line of a contactor is normally closed    */
    CONT_FEEDBACK_TYPE_DONT_CARE    = 0xFF  /*!< Feedback line of the contactor is not used         */
} CONT_FEEDBACK_ELECTRICAL_CONTACT_e;

typedef struct {
    boolean setvalue;
    uint32_t timestamp;
} CONT_STATE_SET_s;

typedef struct {
    CONT_SWITCH_e feedback;
    uint32_t timestamp;
} CONT_STATE_EXPECTATION_s;

typedef struct {
    CONT_SWITCH_e feedback;
    uint32_t timestamp;
} CONT_STATE_MEASUREMENT_s;

typedef struct {
    CONT_STATE_SET_s set;
    CONT_STATE_EXPECTATION_s expectation;
    CONT_STATE_MEASUREMENT_s measurement;
} CONT_STATES_s;

typedef struct {
    IO_PORTS_e control_pin;
    IO_PORTS_e feedback_pin;
    CONT_FEEDBACK_ELECTRICAL_CONTACT_e feedback_pin_electrical_contact;
} CONT_CFG_s;

extern CONT_CFG_s cont_interlock_cfg;
extern CONT_STATES_s cont_interlock_state;
extern CONT_CFG_s cont_contactors_cfg [NR_OF_CONTACTORS];
extern CONT_STATES_s cont_contactor_states[NR_OF_CONTACTORS];

extern const uint8_t cont_contactors_cfg_length;
extern const uint8_t cont_contactors_states_length;

/*================== Function Prototypes ==================================*/

/*================== Function Implementations =============================*/

#endif /* CONTACTOR_CFG_H_ */
