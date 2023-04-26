//
// Created by crk on 23-4-26.
//

#ifndef ADDRESS_BOOK_SYSTEM_PAGE_H
#define ADDRESS_BOOK_SYSTEM_PAGE_H

#include <unordered_map>

template<typename ValueType,typename KeyType>
class Page {
public:
    static int count;
    bool IS_LEAF;
    int page_id;
    int parent_page_id;
    int root_page_id;
    int pin_count;
    bool is_dirty;
    int (*compare)(KeyType,KeyType);
    KeyType *key;
    static const int maxSize = 5;
    int size;
    std::unordered_map<KeyType,ValueType> *data;
    Page() {
        IS_LEAF = false;
        page_id = -1;
        parent_page_id = -1;
        root_page_id = -1;
        pin_count = 0;
        data = nullptr;
        key = new KeyType[maxSize];
    }
};

#endif //ADDRESS_BOOK_SYSTEM_PAGE_H
