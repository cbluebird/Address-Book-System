//
// Created by crk on 23-4-26.
//

#include "../include/BPlusTree.h"
#include "../include/Page.h"

template<typename ValueType, typename KeyType>
BPlusTree<ValueType, KeyType>::BPlusTree() {
    rootPageId=-1;
    bufferPoolManager= new BufferPoolManager<ValueType,KeyType>();
}


template<typename ValueType, typename KeyType>
void BPlusTree<ValueType, KeyType>::insert() {
        int new_root_id;
        Page<ValueType,KeyType>* root=bufferPoolManager->NewPage(new_root_id);
}
