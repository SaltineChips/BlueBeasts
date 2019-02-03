// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "txdb.h"
#include "main.h"
#include "uint256.h"


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
