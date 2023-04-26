//
// Created by crk on 23-4-26.
//

#ifndef ADDRESS_BOOK_SYSTEM_BUFFERPOOLMANAGER_H
#define ADDRESS_BOOK_SYSTEM_BUFFERPOOLMANAGER_H

#include "../include/Page.h"
#include <mutex>
#include <unordered_map>
#include <list>

using page_id_type=int;
using frame_id_t=int;

//内部实现了一个LRU的replacer,同时对Page的一个并发控制
template<typename ValueType,typename KeyType>
class BufferPoolManager {
    BufferPoolManager();
    ~BufferPoolManager(){delete []pages;};
    Page<ValueType,KeyType> *NewPage(page_id_type *page_id);
    Page<ValueType,KeyType>* FetchPage(page_id_type page_id);
    bool UnpinPage(page_id_type page_id, bool is_dirty);
private:

    bool find_replace(frame_id_t *frame_id);
    std::mutex latch;
    const int capacity = 1000;
    std::list<frame_id_t> lru_list;
    std::unordered_map<frame_id_t, std::list<frame_id_t>::iterator> lruMap;
    std::list<frame_id_t>free_list;
    std::unordered_map<page_id_type,frame_id_t>page_table;
    Page<ValueType,KeyType> *pages;

    bool Victim(frame_id_t *frame_id);
    void Pin(frame_id_t frame_id);
    void Unpin(frame_id_t frame_id);
};


#endif //ADDRESS_BOOK_SYSTEM_BUFFERPOOLMANAGER_H
