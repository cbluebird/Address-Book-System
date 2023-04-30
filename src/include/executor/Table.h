//
// Created by crk on 23-4-29.
//

#ifndef ADDRESS_BOOK_SYSTEM_TABLE_H
#define ADDRESS_BOOK_SYSTEM_TABLE_H

#include "src/include/disk/File.h"
#include "src/disk/File.cpp"
#include "src/include/storage/BPlusTree.h"
#include "src/storage/BPlusTree.cpp"

#include <shared_mutex>
#include<mutex>
#include<vector>
#include<thread>



//主要是集合对应的功能，提供相应的接口
template<typename ValueType,typename KeyType>
class Table {
    BPlusTree<ValueType,KeyType>*bPlusTree;
    File<ValueType,KeyType>*file;

public:
    Table(const std::string& path, const std::string& fileType, KeyType(*getMajor)(ValueType));
    ~Table();
    KeyType(*getMajor)(ValueType);

    void insert(KeyType,ValueType);

    void remove(KeyType);

    std::vector<ValueType>queryAll();
    std::vector<ValueType>queryWithMatch(ValueType,bool(*)(ValueType,ValueType));
    ValueType* querySingleWithKey(const KeyType& ) const;
    ValueType* querySingleWithoutKey(const ValueType& ,bool(*)(const ValueType,const ValueType)) const;
    KeyType getEndKey();

    void updateWithoutKey(ValueType&);
    void updateKey(KeyType,ValueType&);
};



#endif //ADDRESS_BOOK_SYSTEM_TABLE_H
