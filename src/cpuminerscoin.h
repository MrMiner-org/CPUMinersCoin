#include <primitives/block.h>
#include <crypto/sha256.h>

// CMC PoW
void CMC(const CBlockHeader *pblock, uint32_t nNonce, uint256 *phash);

void GetPoWHash(const CBlockHeader *pblock, uint256 *thash);

void GetPowHash();