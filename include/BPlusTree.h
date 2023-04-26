//
// Created by yihua on 23-4-26.
//

#ifndef ADDRESS_BOOK_SYSTEM_BPLUSTREE_H
#define ADDRESS_BOOK_SYSTEM_BPLUSTREE_H

#include "BufferPoolManager.h"

template<typename ValueType, typename KeyType>
class BPlusTree {
    BufferPoolManager<ValueType,KeyType> bufferPoolManager;
    int rootPageId;
public:
    void insert();
    BPlusTree();
};



#endif //ADDRESS_BOOK_SYSTEM_BPLUSTREE_H
