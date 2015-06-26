#include "BlobStoreTest.h"

#include <messmer/blockstore/implementations/testfake/FakeBlockStore.h>
#include "../../../../implementations/onblocks/BlobStoreOnBlocks.h"

using blobstore::onblocks::BlobStoreOnBlocks;
using blockstore::testfake::FakeBlockStore;
using cpputils::make_unique_ref;

constexpr uint32_t BlobStoreTest::BLOCKSIZE_BYTES;

BlobStoreTest::BlobStoreTest()
  : blobStore(make_unique_ref<BlobStoreOnBlocks>(make_unique_ref<FakeBlockStore>(), BLOCKSIZE_BYTES)) {
}
