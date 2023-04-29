//
// Created by crk on 23-4-29.
//

#ifndef ADDRESS_BOOK_SYSTEM_PAGE_H
#define ADDRESS_BOOK_SYSTEM_PAGE_H


#include <unordered_map>

//一个node对应一个page，page作块状存储
template<typename ValueType,typename KeyType>
class Page {
public:
    int pin_count;
    bool is_dirty;
    int page_id;
    static int count;
    std::unordered_map<KeyType,ValueType> *data;
    Page();
    void deleteData(KeyType key);
    void Insert(ValueType value,KeyType key);
    ValueType getData(KeyType key);
    void updateData(ValueType,KeyType);
    int getPageId()const{return page_id;}
};

template<typename ValueType,typename KeyType>
int Page<ValueType,KeyType>::count = 1;


#endif //ADDRESS_BOOK_SYSTEM_PAGE_H
