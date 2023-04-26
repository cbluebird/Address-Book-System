//
// Created by crk on 23-4-26.
//

#include "../include/BPlusTreePage.h"

//template<typename ValueType, typename KeyType>
//int InternalPage<ValueType, KeyType>::KeyIndex(const KeyType &k) {
//    int l = 0;
//    int r = GetSize();
//    if (l >= r) {
//        return GetSize();
//    }
//    while (l < r) {
//        int mid = (l + r) / 2;
//        if (compare(key[mid],k) < 0) {
//            l = mid + 1;
//        } else {
//            r = mid;
//        }
//    }
//    return l;
//}
//
//template<typename ValueType, typename KeyType>
//KeyType InternalPage<ValueType, KeyType>::LookUp() {
//    return nullptr;
//}

template<typename ValueType, typename KeyType>
BPlusTreePage<ValueType, KeyType>::BPlusTreePage() {
    data= nullptr;
    size= 0;
}

template<typename ValueType, typename KeyType>
int BPlusTreePage<ValueType, KeyType>::Lookup(const KeyType &key) const {
    return 0;
}

