// Copyright (c) 2016-2019 The CryptoCoderz Team / Espers
// Copyright (c) 2018-2019 The CryptoCoderz Team / INSaNe project
// Copyright (c) 2018-2019 The Rubix project
// Copyright (c) 2018-2019 The BlueBeasts project
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_GENESIS_H
#define BITCOIN_GENESIS_H

#include "bignum.h"

/** Genesis Start Time */
static const unsigned int timeGenesisBlock = 1544904000; // Saturday, December 15, 2018 8:00:00 PM
/** Genesis TestNet Start Time */
static const unsigned int timeTestNetGenesis = 1544904000+30; // Saturday, December 15, 2018 8:00:00 PM
/** Genesis RegNet Start Time */
static const unsigned int timeRegNetGenesis = 1544904000+90; // Saturday, December 15, 2018 8:00:00 PM
/** Genesis Nonce Mainnet*/
static const unsigned int nNonceMain = 24768;
/** Genesis Nonce Testnet */
static const unsigned int nNonceTest = 2868;
/** Genesis Nonce Regnet */
static const unsigned int nNonceReg = 8;
/** Main Net Genesis Block */
static const uint256 nGenesisBlock("0x00006dfa0fec1755bed8d26474969c29fcc63e2e7abd6032e79e548c15094767");
/** Test Net Genesis Block */
static const uint256 hashTestNetGenesisBlock("0x0002a59dd63d5fa8b515f15144ce6a7ada594e63371f652f833e555e7e3b33b7");
/** Reg Net Genesis Block */
static const uint256 hashRegNetGenesisBlock("0x3762eb656c953854e41c33f6691bd723cca09817d4a6b7bae214e88e3c3c73d4");
/** Genesis Merkleroot */
static const uint256 nGenesisMerkle("0xe7de676978b0c7cc62b0ed631929044ac04c9143c83833f4f46cf347a0ac9a94");

#endif // BITCOIN_GENESIS_H
