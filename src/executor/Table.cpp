//
// Created by crk on 23-4-29.
//

#include "src/include/executor/Table.h"

template<typename ValueType, typename KeyType>
Table<ValueType, KeyType>::~Table() {
    delete file;
    delete bPlusTree;
}

template<typename ValueType, typename KeyType>
Table<ValueType, KeyType>::Table(const std::string &path, const std::string &fileType, KeyType(*key)(ValueType)) {
    readLock=0;
    writeLock=0;
    file=new File<ValueType,KeyType>(path,fileType);
    bPlusTree=new BPlusTree<ValueType,KeyType>;
    std::unordered_map<KeyType,ValueType>temp=file->init(key);
    for(auto it=temp.begin();it!=temp.end();++it){
        bPlusTree->insert(it->first,it->second);
    }
    getMajor=key;
}

template<typename ValueType, typename KeyType>
bool Table<ValueType, KeyType>::insert(KeyType key, ValueType value) {
    if(readLock!=0||writeLock!=0)return false;
    writeLock=1;
    bPlusTree->insert(key,value);
    file->insert(value);
    writeLock=0;
    return true;
}

template<typename ValueType, typename KeyType>
std::vector<ValueType> Table<ValueType, KeyType>::queryAll() {
    std::vector<ValueType>ans=bPlusTree->queryAll();
    return ans;
}

template<typename ValueType, typename KeyType>
bool Table<ValueType, KeyType>::remove(KeyType key) {
    if(readLock!=0||writeLock!=0)return false;
    writeLock=1;
    bPlusTree->remove(key);
    std::vector<ValueType>ans=bPlusTree->queryAll();
    file->update(ans);
    writeLock=0;
    return true;
}


template<typename ValueType, typename KeyType>
ValueType *Table<ValueType, KeyType>::querySingleWithKey(const KeyType &key) const {
    auto ans=bPlusTree->querySingleWithKey(key);
    return ans;
}

template<typename ValueType, typename KeyType>
ValueType *Table<ValueType, KeyType>::querySingleWithoutKey(const ValueType &value, bool (*key)(const ValueType, const ValueType)) const {
    auto ans=bPlusTree->querySingleWithoutKey(value,key);
    return ans;
}

template<typename ValueType, typename KeyType>
bool Table<ValueType, KeyType>::updateWithoutKey(ValueType& value) {
    if(readLock!=0||writeLock!=0)return false;
    writeLock=1;
    auto key=getMajor(value);
    bPlusTree->updateWithoutKey(key, value);
    auto ans=bPlusTree->queryAll();
    file->update(ans);
    writeLock=0;
    return true;
}

template<typename ValueType, typename KeyType>
bool Table<ValueType, KeyType>::updateKey(KeyType origin, ValueType& value) {
    if(readLock!=0||writeLock!=0)return false;
    writeLock=1;
    auto newKey=getMajor(value);
    bPlusTree->updateKey(origin,newKey,value);
    auto ans=bPlusTree->queryAll();
    file->update(ans);
    writeLock=0;
    return true;
}