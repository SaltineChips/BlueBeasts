// Copyright (c) 2016-2019 The CryptoCoderz Team / Espers
// Copyright (c) 2018-2019 The CryptoCoderz Team / INSaNe project
// Copyright (c) 2018-2019 The Rubix project
// Copyright (c) 2019 The BlueBeasts developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_MINING_H
#define BITCOIN_MINING_H

#include "bignum.h"

/** Minimum nCoinAge required to stake PoS */
static const unsigned int nStakeMinAge = 2 / 60; // 30 minutes
/** Time to elapse before new modifier is computed */
static const unsigned int nModifierInterval = 2 * 60;
/** Genesis block subsidy */
static const int64_t nGenesisBlockReward = 1 * COIN;
/** Reserve block subsidy */
static const int64_t nBlockRewardReserve = 2239275 * COIN; // 2.5% Reserved for Development ~223.9275 Million
/** Standard block subsidy */
static const int64_t nBlockStandardReward = 950 * COIN;
/** Superblock block subsidy */
static const int64_t nBlockSuperReward = 1240 * COIN;
/** Block spacing preferred */
static const int64_t BLOCK_SPACING = 270;
/** Block spacing minimum */
static const int64_t BLOCK_SPACING_MIN = 135;
/** Block spacing maximum */
static const int64_t BLOCK_SPACING_MAX = 405;
/** Desired block times/spacing */
static const int64_t GetTargetSpacing = BLOCK_SPACING;
/** MNengine collateral */
static const int64_t MNengine_COLLATERAL = (1 * COIN);
/** MNengine pool values */
static const int64_t MNengine_POOL_MAX = (999 * COIN);
/** MasterNode required collateral */
inline int64_t MasternodeCollateral(int nHeight) { return 65000; } // 65K TBB required as collateral
/** Coinbase transaction outputs can only be staked after this number of new blocks (network rule) */
static const int nStakeMinConfirmations = 25;
/** Coinbase transaction outputs can only be spent after this number of new blocks (network rule) */
static const int nCoinbaseMaturity = 15; // 15-TXs | 90-Mined


#endif // BITCOIN_MINING_H
