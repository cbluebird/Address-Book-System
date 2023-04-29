//
// Created by crk on 23-4-29.
//

#ifndef ADDRESS_BOOK_SYSTEM_NODE_H
#define ADDRESS_BOOK_SYSTEM_NODE_H


template<typename KeyType>
class Node {
public:
    bool IS_LEAF;
    int  size;
    Node<KeyType>** ptr;
    Node<KeyType>* parent;
    static const int MAX = 4;
    KeyType *key;
    int page_id;
public:
    Node();
};


#endif //ADDRESS_BOOK_SYSTEM_NODE_H
