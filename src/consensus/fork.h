// Copyright (c) 2016-2019 The CryptoCoderz Team / Espers
// Copyright (c) 2018-2019 The Rubix project
// Copyright (c) 2019 The BlueBeasts developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_FORK_H
#define BITCOIN_FORK_H

#include "primitives/bignum.h"
#include "mining.h"

/** Reserve Phase start block */ 
static const int64_t nReservePhaseStart = 1;
/** Velocity toggle block */
static const int64_t VELOCITY_TOGGLE = 300; // Implementation of the Velocity system into the chain.
/** Velocity retarget toggle block */
static const int64_t VELOCITY_TDIFF = 0; // Use Velocity's retargetting method.
/** Protocol 3.0 toggle */
inline bool IsProtocolV3(int64_t nTime) { return TestNet() || nTime > 1493596800; } // Mon, 01 May 2017 00:00:00 GMT
#endif // BITCOIN_FORK_H
