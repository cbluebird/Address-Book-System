//
// Created by crk on 23-4-29.
//

#ifndef ADDRESS_BOOK_SYSTEM_BPLUSTREE_H
#define ADDRESS_BOOK_SYSTEM_BPLUSTREE_H

#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
#include<vector>

#include "Node.h"
#include "src/include/buffer/BufferPoolManager.h"
#include "src/buffer/BufferPoolManager.cpp"
#include "src/storage/Node.cpp"

template<typename ValueType, typename KeyType>
class Iterator {
private:
    Node<KeyType>* m_start;//起始指向
    Node<KeyType>* m_cur;//现在指向
    Node<KeyType>* m_end;//中止指向
    int cur;
public:
    Node<KeyType>* getCur();
    Iterator<ValueType,KeyType>& operator=(const Iterator<ValueType,KeyType>&);
    Iterator<ValueType,KeyType> operator++(int);
    void gotoNextNode();
    Iterator();
    Iterator(Node<KeyType>*,Node<KeyType>*);
};


template<typename ValueType,typename KeyType>
class BPlusTree {
    Node<KeyType> *root;
    BufferPoolManager<ValueType,KeyType> *buffer_pool_manager;

    friend class Iterator<ValueType,KeyType>;

    Node<KeyType> *begin() const;
    Node<KeyType> *end() const;
    void insertInternal(KeyType,Node<KeyType>*,Node<KeyType>*,Node<KeyType>*);
    void split(KeyType ,Node<KeyType> *,Node<KeyType> *,ValueType);
    int insertVal(KeyType ,Node<KeyType> *);
    void removeInternal(KeyType, Node<KeyType> *, Node<KeyType> *);
    Node<KeyType> *findParent(Node<KeyType> *, Node<KeyType> *);

public:
    BPlusTree();
    void insert(KeyType,ValueType);
    void remove(KeyType);
    void display();
    bool updateWithoutKey(KeyType,ValueType);
    bool updateKey(KeyType,KeyType,ValueType);
    ValueType* querySingleWithKey(const KeyType& ) const;
    ValueType* querySingleWithoutKey(const ValueType& ,bool(*)(const ValueType,const ValueType));
    std::vector<ValueType> queryAll();
    Node<KeyType> *getRoot();
};



#endif //ADDRESS_BOOK_SYSTEM_BPLUSTREE_H
