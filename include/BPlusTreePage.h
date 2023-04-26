//
// Created by yihua on 23-4-26.
//

#ifndef ADDRESS_BOOK_SYSTEM_BPLUSTREEPAGE_H
#define ADDRESS_BOOK_SYSTEM_BPLUSTREEPAGE_H

#include "Page.h"
#include <unordered_map>

template<typename ValueType,typename KeyType>
class BPlusTreePage{
    public:
    BPlusTreePage();
    int Lookup(const KeyType &key)const;
};



#endif //ADDRESS_BOOK_SYSTEM_BPLUSTREEPAGE_H
