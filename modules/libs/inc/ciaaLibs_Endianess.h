/* Copyright 2015, Daniel Cohen
 * Copyright 2015, Esteban Volentini
 * Copyright 2015, Matias Giori
 * Copyright 2015, Franco Salinas
 * Copyright 2015, Pablo Alcorta
 * 
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef UPDT_UTILS_H
#define UPDT_UTILS_H
/** \brief Flash Update Utils header file
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * DC           Daniel Cohen
 * EV           Esteban Volentini
 * MG           Matias Giori
 * FS           Franco Salinas
 * PA		Pablo Alcorta
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20151013 v0.0.1  FS PA first initial version
 */

/*==================[inclusions]=============================================*/
#include "ciaaPOSIX_stdint.h"

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/
#define ciaaLibs_utilsHtonll ciaaLibs_utilsNtohll
#define ciaaLibs_utilsHtonl ciaaLibs_utilsNtohl
#define ciaaLibs_utilsHtons ciaaLibs_utilsNtohs

#if CIAAPLATFORM_BIGENDIAN == CIAA_ENABLE
#define ciaaLibs_setHigh(ptr) ciaaLibs_utilsNtohl (*(ptr)+1)
#else 
#define ciaaLibs_setLow(ptr) ciaaLibs_utilsNtohl (*(ptr))
#endif
#if CIAAPLATFORM_BIGENDIAN == CIAA_ENABLE
#define ciaaLibs_setLow(ptr) ciaaLibs_utilsNtohl (*(ptr))
#else
#define ciaaLibs_setHigh(ptr) ciaaLibs_utilsNtohl (*(ptr+1))
#endif
/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/
uint16_t ciaaLibs_utilsNtohs(uint16_t netshort);
uint32_t ciaaLibs_utilsNtohl(uint32_t netlong);
uint64_t ciaaLibs_utilsNtohll(uint64_t netlonglong);
/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef UPDT_UTILS_H */
