/*
 *  Copyright (c) 2016, The OpenThread Authors.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 * @brief
 *  This file defines the top-level functions for the OpenThread CoAP Secure implementation.
 */

#ifndef OPENTHREAD_COAP_SECURE_H_
#define OPENTHREAD_COAP_SECURE_H_

#include <stdint.h>

#include <openthread/message.h>
#include <openthread/types.h>

#include <openthread/coap.h>		// include for coap & coap header typdefs

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup api-coap-secure
 *
 * @brief
 *   This module includes functions that control CoAP Secure (CoAP over TLS) communication.
 *
 *   The functions in this module are available when application-coap-secure feature (`OPENTHREAD_ENABLE_APPLICATION_COAP_SECURE`) is
 *   enabled.
 *
 * @{
 *
 */

#define OT_DEFAULT_COAP_SECURE_PORT  5684  ///< Default CoAP Secure port, as specified in RFC 7252

//TODO: remove, only for testing!!!
/**
 * This function is only for test the integration of coaps api.
 * It has no further function for coaps.
 *
 * @param[inout]  aCount           	A pointer to a value. Will increment at one.
 *
 * @retval 		OT_ERROR_NONE     	Successfully call this function.
 */
otError otCoapSecureTestIntegration(uint8_t * aCount);

/**
 * This function starts the CoAP Secure server.
 *
 * @param[in]  aInstance  A pointer to an OpenThread instance.
 * @param[in]  aPort      The local UDP port to bind to.
 *
 * @retval OT_ERROR_NONE  Successfully started the CoAP Secure server.
 *
 */
otError otCoapSecureStart(otInstance *aInstance, uint16_t aPort, void *aContext);

/**
 * This function stops the CoAP Secure server.
 *
 * @param[in]  aInstance  A pointer to an OpenThread instance.
 *
 * @retval OT_ERROR_NONE  Successfully stopped the CoAP Secure server.
 */
otError otCoapSecureStop(otInstance *aInstance);
otError otCoapSecureSetPSK(otInstance *aInstance, uint8_t *mPsk, uint8_t length);

typedef void (*otHandleSecureCoapClientConnect)(bool aConnected, void *aContext);
otError otCoapSecureConnect(otInstance *aInstance,const otMessageInfo * aMessageInfo,  otHandleSecureCoapClientConnect aHandler, void *aContext);


/**
 * @}
 *
 */

#ifdef __cplusplus
}  // extern "C"
#endif

#endif /* OPENTHREAD_COAP_SECURE_H_ */