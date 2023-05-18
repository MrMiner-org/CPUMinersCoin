	// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <chainparams.h>
#include <genesis.h>
#include <consensus/merkle.h>

#include <tinyformat.h>
#include <util.h>
#include <utilstrencodings.h>

#include <assert.h>
#include <memory>

#include <chainparamsseeds.h>
#include <arith_uint256.h>
#include <pthread.h>

/**
 * Main network
 */
/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.BIP16Height = 0;
        consensus.BIP34Height = 0;
        consensus.powLimit = uint256S("0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");

        consensus.nTargetTimespan = 24 * 60 * 60;
        consensus.nStakeTargetSpacing = 2 * 60;
        consensus.nTargetSpacingWorkMax = 2 * consensus.nStakeTargetSpacing;
        consensus.nPowTargetSpacing = consensus.nStakeTargetSpacing;
        consensus.nStakeMinConfirmations = 10;
        consensus.nCoinbaseMaturity = 20;
        consensus.nDgwPastBlocks = 30;
	

        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.nStartMiningTime = 1655555555;
		
        // The best chain should have at least this much work.
		consensus.nMinimumChainWork = uint256S("0x00");
        // By default assume that the signatures in ancestors of this block are valid.
		consensus.defaultAssumeValid = uint256S("0x00");

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 32-bit integer with any alignment.
         */
        pchMessageStart[0] = 0x3e;
        pchMessageStart[1] = 0x8b;
        pchMessageStart[2] = 0xa5;
        pchMessageStart[3] = 0x55;
        vAlertPubKey = ParseHex("04c5b144e0cf83da41b1a2481e7f5df8510cbde0e892505b7d9c943e9bae7f2f145f002bba397474bf4c150529d841bb1a216a76b103075a191c7e575164316f94");
        nDefaultPort = 15995;

        genesis = CreateGenesisBlock(1655555555, 800149319, 0x1f00ffff, 1, 0);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x8543d67f02bf6813aa1af5eefd53aeb56c31b4cc042af2924093b1d15b71141d"));
        assert(genesis.hashMerkleRoot == uint256S("0xb829c6a0860ea65b94dec0d2d48b1c6302668542f240ed89459a1adc2c09a00d"));
        vSeeds.emplace_back("seed01.cpuminerscoin.com");
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,28);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,50);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,156);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x88, 0xB2, 0x1E}; // xpub
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x88, 0xAD, 0xE4}; // xprv

        // human readable prefix to bench32 address
        bech32_hrp = "cmc";

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));

        nMiningRequiresPeers = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;

        checkpointData = {
            {
                {1, uint256S("0x4466132fd5cbce3aa939e49c0a082b12b880e5fca7f45919f664614b2ad8b144")},
				{3, uint256S("0x0e260802c27fa3b18e9c5f07c5d7d0c9b153a6a3acd209b6d9f204f8d190b2f4")},
				{9, uint256S("0x157fa52a1ecc172f1e5db8b4cb90f2b3c469afef6fa5032ca9bfe2af60e89ec7")},
            }
        };

        chainTxData = ChainTxData{
			1655555555, //nTime
			0, //nTxCount
			0 //dTxRate
        };
    }
};

/**
 * Testnet (v3)
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
        strNetworkID = "test";
        consensus.BIP16Height = 0;
        consensus.BIP34Height = 0;
        consensus.powLimit = uint256S("000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nTargetTimespan = 24 * 60;  // 24 minutes
        consensus.nStakeTargetSpacing = 1 * 60;  // 1-minute block spacing
        consensus.nTargetSpacingWorkMax = 1 * consensus.nStakeTargetSpacing; // 24-minute
        consensus.nPowTargetSpacing = consensus.nStakeTargetSpacing;
        consensus.nStakeMinConfirmations = 1;
        consensus.nCoinbaseMaturity = 6; // 6 confirmations
        consensus.nDgwPastBlocks = 30;


        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.nStartMiningTime = 1655555555;

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x00");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x00");

        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0x1a;
        pchMessageStart[2] = 0xf9;
        pchMessageStart[3] = 0xbf;
        nDefaultPort = 15998;
        vAlertPubKey = ParseHex("041a99ac3d74a8a743d6581c7296086d1850ee979c55318bdf2ce84f3458c1c3332935663359cd94ada0cdeee1fcd888e611dabd52ccfd0f5822a63f5cef3a444b");
        genesis = CreateGenesisBlock(1655555555, 1400160225, 0x1f00ffff, 1, 0);
		
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x3e379aabb574918241fd0052bb192f8f2e641072886a415cd2d584ccf4182e93"));
        assert(genesis.hashMerkleRoot == uint256S("0xb829c6a0860ea65b94dec0d2d48b1c6302668542f240ed89459a1adc2c09a00d"));

        vFixedSeeds.clear();
        vSeeds.clear();


        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,28);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,50);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,156);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF}; // tpub
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94}; // tprv

        // human readable prefix to bench32 address
        bech32_hrp = "tcmc";

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));

        nMiningRequiresPeers = 1;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        checkpointData = {
            {
                {0, uint256S("0x8543d67f02bf6813aa1af5eefd53aeb56c31b4cc042af2924093b1d15b71141d")},
            }
        };

        chainTxData = ChainTxData{
                1655555555,
                0,
                0
        };

    }
};

/**
 * Regression test
 */

class CRegTestParams : public CChainParams {
public:
    CRegTestParams() {
        strNetworkID = "regtest";
        consensus.BIP16Height = 0; // always enforce P2SH BIP16 on regtest
        consensus.BIP34Height = 0; // BIP34 has not activated on regtest (far in the future so block v1 are not rejected in tests)
        consensus.BIP34Hash = uint256();
        consensus.powLimit = uint256S("000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"); // ~arith_uint256(0) >> 28;
        consensus.nTargetTimespan = 3 * 24 * 60 * 60; // two weeks
        consensus.nStakeTargetSpacing = 1 * 60; // 1-minute block spacing
        consensus.nTargetSpacingWorkMax = 1 * consensus.nStakeTargetSpacing; //
        consensus.nPowTargetSpacing = consensus.nStakeTargetSpacing;
        consensus.nStakeMinConfirmations = 1; //
        consensus.nCoinbaseMaturity = 2;
        consensus.nDgwPastBlocks = 3;


        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = true;
        consensus.nStartMiningTime = 1655555555;

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x00");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x00");

        pchMessageStart[0] = 0xb1;
        pchMessageStart[1] = 0x6e;
        pchMessageStart[2] = 0x4e;
        pchMessageStart[3] = 0x9f;
        nDefaultPort = 15993;
        vAlertPubKey = ParseHex("04fb0a570737c4d4e4898950a6b534d34edeaaee9faf5b4cf276ae1d67c820bb85943414420c3aec419b319da9fdcc5f28b2829010f30c189620a38fcee3063ce2");
        genesis = CreateGenesisBlock(1655555555, 900183180, 0x1f00ffff, 1, 0);
		
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x32ee9263a72f364ac1f72cf510416a287d2fc0115a3948125ac6b3a3d3172221"));
        assert(genesis.hashMerkleRoot == uint256S("0xb829c6a0860ea65b94dec0d2d48b1c6302668542f240ed89459a1adc2c09a00d"));

        vFixedSeeds.clear(); //!< Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();      //!< Regtest mode doesn't have any DNS seeds.

        checkpointData = {
            {
                {0, uint256S("0x8543d67f02bf6813aa1af5eefd53aeb56c31b4cc042af2924093b1d15b71141d")},
            }
        };

        chainTxData = ChainTxData{
            1655555555,
            0,
            0
        };

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,28);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,50);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,156);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF}; // tpub
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94}; // tprv

        bech32_hrp = "rtcmc";

        nMiningRequiresPeers = 0;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
    }
};

static std::unique_ptr <CChainParams> globalChainParams;

const CChainParams &Params() {
    assert(globalChainParams);
    return *globalChainParams;
}

std::unique_ptr <CChainParams> CreateChainParams(const std::string &chain) {
    if (chain == CBaseChainParams::MAIN)
        return std::unique_ptr<CChainParams>(new CMainParams());
    else if (chain == CBaseChainParams::TESTNET)
        return std::unique_ptr<CChainParams>(new CTestNetParams());
    else if (chain == CBaseChainParams::REGTEST)
        return std::unique_ptr<CChainParams>(new CRegTestParams());
    throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectParams(const std::string &network) {
    SelectBaseParams(network);
    globalChainParams = CreateChainParams(network);
}
