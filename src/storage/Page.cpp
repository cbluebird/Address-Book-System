//
// Created by crk on 23-4-29.
//

#include "include/storage/Page.h"

template<typename ValueType, typename KeyType>
Page<ValueType, KeyType>::Page() {
    page_id = -1;
    pin_count = 0;
    data =new std::unordered_map<KeyType,ValueType>;

}

template<typename ValueType, typename KeyType>
void Page<ValueType, KeyType>::Insert(ValueType value, KeyType key) {
    data->insert(std::make_pair(key,value));
}

template<typename ValueType, typename KeyType>
void Page<ValueType, KeyType>::deleteData(KeyType key) {
    data->erase(key);
}

template<typename ValueType, typename KeyType>
ValueType Page<ValueType, KeyType>::getData(KeyType key) {
    ValueType value = (*data)[key];
    return value;
}

template<typename ValueType, typename KeyType>
void Page<ValueType, KeyType>::updateData(ValueType value, KeyType key) {
    deleteData(key);
    Insert(value,key);
}
