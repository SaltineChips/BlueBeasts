// Copyright (c) 2016-2019 The CryptoCoderz Team / Espers
// Copyright (c) 2018-2019 The CryptoCoderz Team / INSaNe project
// Copyright (c) 2017-2019 The Rubix project
// Copyright (c) 2018-2019 The Endox project
// Copyright (c) 2019-2019 The BlueBeasts project
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_GENESIS_H
#define BITCOIN_GENESIS_H

#include "primitives/bignum.h"

/** Genesis Start Time */
static const unsigned int timeGenesisBlock = 1547971200; // Saturday, December 15, 2018 8:00:00 PM
/** Genesis TestNet Start Time */
static const unsigned int timeTestNetGenesis = 1547971200+30; // Saturday, December 15, 2018 8:00:00 PM
/** Genesis RegNet Start Time */
static const unsigned int timeRegNetGenesis = 1547971200+90; // Saturday, December 15, 2018 8:00:00 PM
/** Genesis Nonce Mainnet*/
static const unsigned int nNonceMain = 84159;
/** Genesis Nonce Testnet */
static const unsigned int nNonceTest = 20838;
/** Genesis Nonce Regnet */
static const unsigned int nNonceReg = 8;
/** Main Net Genesis Block */
static const uint256 nGenesisBlock("0x0000def26124d03147fc55f263467856aa3e1f54b62e256c7cef56878f97ee9f");
/** Test Net Genesis Block */
static const uint256 hashTestNetGenesisBlock("0x00020a06f69c91832fbace0e4c5db6bf35432c8a3a9f88469da308c28551e9d9");
/** Reg Net Genesis Block */
static const uint256 hashRegNetGenesisBlock("0x01efdddac6a979b0e89c84dedc0dcb29b4834b89cea514fefb689cbf188b42d8");
/** Genesis Merkleroot */
static const uint256 nGenesisMerkle("0x7e4a56d5f02212f77401ab68d785afcdc8b905400f6edb6c9ef32bc73e6d2584");

#endif // BITCOIN_GENESIS_H
