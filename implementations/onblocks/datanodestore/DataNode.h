#pragma once
#ifndef BLOBSTORE_IMPLEMENTATIONS_ONBLOCKS_DATANODESTORE_DATANODE_H_
#define BLOBSTORE_IMPLEMENTATIONS_ONBLOCKS_DATANODESTORE_DATANODE_H_

#include "DataNodeView.h"
#include <messmer/cpp-utils/data/Data.h>

namespace blobstore {
namespace onblocks {
namespace datanodestore {
class DataNodeStore;
class DataInnerNode;

class DataNode {
public:
  virtual ~DataNode();

  const blockstore::Key &key() const;

  uint8_t depth() const;

  static cpputils::unique_ref<DataInnerNode> convertToNewInnerNode(cpputils::unique_ref<DataNode> node, const DataNode &first_child);

  void flush() const;

protected:
  DataNode(DataNodeView block);

  DataNodeView &node();
  const DataNodeView &node() const;
  friend class DataNodeStore;

private:
  DataNodeView _node;

  DISALLOW_COPY_AND_ASSIGN(DataNode);
};

}
}
}


#endif
