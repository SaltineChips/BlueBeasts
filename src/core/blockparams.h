// Copyright (c) 2016-2019 The CryptoCoderz Team / Espers
// Copyright (c) 2018-2019 The CryptoCoderz Team / INSaNe project
// Copyright (c) 2018-2019 The Rubix project
// Copyright (c) 2018-2019 The Endox Developers
// Copyright (c) 2019 The BlueBeasts Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_BLOCKPARAMS_H
#define BITCOIN_BLOCKPARAMS_H

#include "node/net.h"
#include "chain.h"
#include "primitives/bignum.h"
#include "primitives/base58.h"

#define START_MASTERNODE_PAYMENTS_TESTNET      9993058800  // OFF (NOT TOGGLED)
#define START_MASTERNODE_PAYMENTS              1550260800  // ON  (February 15, 2019 8:00:00 PM)
#define STOP_MASTERNODE_PAYMENTS_TESTNET       9993058800  // OFF (NOT TOGGLED)
#define STOP_MASTERNODE_PAYMENTS               9993058800  // OFF (NOT TOGGLED)

#define START_DEVOPS_PAYMENTS_TESTNET          1548072000  // ON  (Monday, January 21, 2019 12:00:00 PM)
#define START_DEVOPS_PAYMENTS                  1550174400  // ON  (Thursday, February 14, 2019 8:00:00 PM)
#define STOP_DEVOPS_PAYMENTS_TESTNET           9993058800  // OFF (NOT TOGGLED)
#define STOP_DEVOPS_PAYMENTS                   9993058800  // OFF (NOT TOGGLED)

#define INSTANTX_SIGNATURES_REQUIRED           2
#define INSTANTX_SIGNATURES_TOTAL              4

// Define difficulty retarget algorithms
enum DiffMode {
    DIFF_DEFAULT = 0, // Default to invalid 0
    DIFF_VRX     = 1, // Retarget using Terminal-Velocity-RateX
};

void VRXswngdebug();
void VRXdebug();
void GNTdebug();
void VRX_BaseEngine(const CBlockIndex* pindexLast, bool fProofOfStake);
void VRX_Simulate_Retarget();
void VRX_ThreadCurve(const CBlockIndex* pindexLast, bool fProofOfStake);
void VRX_Dry_Run(const CBlockIndex* pindexLast);
unsigned int VRX_Retarget(const CBlockIndex* pindexLast, bool fProofOfStake);
unsigned int GetNextTargetRequired(const CBlockIndex* pindexLast, bool fProofOfStake);
int64_t GetProofOfWorkReward(int nHeight, int64_t nFees);
int64_t GetProofOfStakeReward(const CBlockIndex* pindexPrev, int64_t nCoinAge, int64_t nFees);
int64_t GetMasternodePayment(int nHeight, int64_t blockValue);
int64_t GetDevOpsPayment(int nHeight, int64_t blockValue);


#endif // BITCOIN_BLOCKPARAMS_H