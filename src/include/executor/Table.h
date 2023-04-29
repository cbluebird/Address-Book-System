//
// Created by crk on 23-4-29.
//

#ifndef ADDRESS_BOOK_SYSTEM_TABLE_H
#define ADDRESS_BOOK_SYSTEM_TABLE_H

#include "src/include/disk/File.h"
#include "src/disk/File.cpp"
#include "src/include/storage/BPlusTree.h"
#include "src/storage/BPlusTree.cpp"
#include<vector>

//主要是集合对应的功能，提供相应的接口
template<typename ValueType,typename KeyType>
class Table {
    BPlusTree<ValueType,KeyType>*bPlusTree;
    File<ValueType,KeyType>*file;
    int readLock;
    int writeLock;
    KeyType(*getMajor)(ValueType);
public:
    Table(const std::string& path, const std::string& fileType, KeyType(*getMajor)(ValueType));
    ~Table();
    bool insert(KeyType,ValueType);

    bool remove(KeyType);

    std::vector<ValueType>queryAll();
    ValueType* querySingleWithKey(const KeyType& ) const;
    ValueType* querySingleWithoutKey(const ValueType& ,bool(*)(const ValueType,const ValueType)) const;

    bool updateWithoutKey(ValueType&);
    bool updateKey(KeyType,ValueType&);
};



#endif //ADDRESS_BOOK_SYSTEM_TABLE_H
