/*******************************************************************************
 * Copyright (c)  2015  Dipl.-Ing. Tobias Rohde, http://www.lobaro.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *******************************************************************************/
#ifndef COAP_MAIN_H_
#define COAP_MAIN_H_


#define MAX_CONCURRENT_TRANSACTIONS (10)

#define MAX_FAIL_RETRIES (4)


#define POSTPONE_WAIT_TIME_SEK (3)
#define POSTPONE_MAX_WAIT_TIME (30)

#define HOLDTIME_AFTER_NON_TRANSACTION_END (0)

#define CLIENT_MAX_RESP_WAIT_TIME (45)


#define USE_RFC7641_ADVANCED_TRANSMISSION (1)

#define ACK_TIMEOUT (2)
#define ACK_RANDOM_FACTOR (1.5)
#define MAX_RETRANSMIT (4)
#define NSTART (1)
#define DEFAULT_LEISURE (5)
#define PROBING_RATE (1) 		//[client]


//#####################
// Receive of packets
//#####################
// This function must be called by network drivers
// on reception of a new network packets which
// should be passed to the CoAP stack.
// "ifID" can be chosen arbitrary by calling network driver,
// but can be considered constant over runtime.
void CoAP_onNewPacketHandler( uint8_t ifID, NetPacket_t* pckt);

//#####################
// Transmit of packets
//#####################
//stack uses "NetSocket_t* RetrieveSocket2(uint8_t ifID)" function to get socket / send function inside socket

CoAP_Result_t  CoAP_Init(uint8_t* pMemory, int16_t MemorySize);
void CoAP_doWork();


#endif
