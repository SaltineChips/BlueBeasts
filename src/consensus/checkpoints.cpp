// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "database/txdb.h"
#include "core/main.h"
#include "primitives/uint256.h"


static const int nCheckpointSpan = 5000;

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (0,     Params().HashGenesisBlock() )
        (1,     uint256("0x000026960d3b19e16f6a62cf0eb599bca8fb7570c846d7cb476446bc57aa094a"))
        (2,     uint256("0x00000fb9d8bdc8d2177d8a20b669d782183978da1665d3d3bbb861cc941898d5"))
        (25,   uint256("00000803f51b5fbba227d21107f2c54e99639cff5eb21669113988da0a0b0986"))
        (50,   uint256("0x00001b3512167a6c664f01b297d2733df4925fbe961b0d7f777d39643c89708c"))
        (75,   uint256("0x00008e75e7a648e77d94c12cbf39517c53204b0904535fc53500216d2004c042"))
        (90,   uint256("0x000016217e0cc614b87bf6efbf75f734bbcdc773f622dfb7fb8a082f512bc1ad"))
        (100, uint256("0xa64e35c512bfaba772580530148e8d314609d25dec4f545bcaf98f959501cc5f"))
        (125, uint256("8a150abdb9bf65f07a24c8cc58f26b0b224de1c4eb4e69280f416f8ef4958f43"))
        (140, uint256("422c48f4de00d8864dd5481b4537b160e42ef2b676f3f9c80c965d065e90e299"))
        (150, uint256("0000036d9de1124a11e5e8714f1aa08a847f67d56b7a4012c321f462c778ca8f"))
        (175, uint256("0000000000058ab4c6dfce4e88ef937e94a3e1771791c0af0d9cefe6b02004a0"))
        (200, uint256("0000000000021ecba94e795b3bf1f7ccbf48d4ccfa9bbcd9b098025695f12e97"))
        (225, uint256("0000000000023a316fd7834be9a022ac73888bfbc92cacfc1bcc51f2c796e466"))
        (250, uint256("0000000000007f65c929ce8f71fe102617d0a10b81607aa592dea9c99fbf77db"))
        (280, uint256("000000000000b8147fd948f135f95e537a21c965cfeaedfeb3b703fd16b5caac"))
        (300, uint256("ffeb454ebc877e2f6a96a71386eb40befd01b686f194529e991648f8c5da7ffd"))
        (325, uint256("0000000000013b8b996ae63887129374da7933c5386e7ee6c5761a65c4135ec0"))
        (350, uint256("033b5c7d7e5ca96aafb785d04089f0d2e5406853fae58bfd439ccfa82d84677d"))
        (375, uint256("0000000000002c4edc112393dd9ba3acb16e83b4a4a2a7b63bea30e9bf1089d0"))
        (400, uint256("0f023b642b3e8539755b789a3b383787b09f0118d112c1a19f722e87d5c4f187"))
        (415, uint256("94d5a7cf681c0fa9f974c255ab2a2782d8111e910d2530aa52de442a51a592e7"))
        (500, uint256("0000000000025e57146e9270dcdd4f20087042bba042ffdda008d5d79bced024"))
        (750, uint256("696e027ff70c27f1bd01ae9598914ef8171f0fc3fefd0ed8d08a061fb5b243b8"))
        (800, uint256("34a3394125e4f83e0b4381a8a1086d1c338a71f064ca33369c108c83fd9de914"))
        (1000, uint256("c2a960169f9eb9cc57c05c13941e1a4788203ccb9a0a812259fa15cff953b2de"))
        (1200, uint256("ae5f470ad0c6320f10ea34ac33bc9a864141cb0ba90f7dd24137c6ab9a8ce358"))
        (1400, uint256("32a3d85beb29cbf25905f30941f0c9038620d0662afdab097d3e7e25187294eb"))
        (1850, uint256("8aaea511caf7b1881dfde0ca0084d3a499c4c4072b16b64d978c2730ce6b8d93"))
        (2000, uint256("551a22ae8781be36899514f11c88e6c43777b8b389f440802fd7bf88ee91ed9f"))
        (2400, uint256("11df9761d325d1bb1d904a2ee69c496508f19f9354fde5dd26a0c15a36f09b15"))
        (2430, uint256("291c1c85fc3cbb9222804ee675a206acba08713d8133948712560f5f1f675620"))
    ;

    // TestNet has no checkpoints
    static MapCheckpoints mapCheckpointsTestnet;

    bool CheckHardened(int nHeight, const uint256& hash)
    {
        MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

        if (checkpoints.empty())
            return 0;
        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }

    // Automatically select a suitable sync-checkpoint
    const CBlockIndex* AutoSelectSyncCheckpoint()
    {
        const CBlockIndex *pindex = pindexBest;
        // Search backward for a block within max span and maturity window
        while (pindex->pprev && pindex->nHeight + nCheckpointSpan > pindexBest->nHeight)
            pindex = pindex->pprev;
        return pindex;
    }

    // Check against synchronized checkpoint
    bool CheckSync(int nHeight)
    {
        const CBlockIndex* pindexSync = AutoSelectSyncCheckpoint();
        if (nHeight <= pindexSync->nHeight){
            return false;
        }
        return true;
    }
}
