//
// Created by crk on 23-4-25.
//

#ifndef ADDRESS_BOOK_SYSTEM_BPTREE_H
#define ADDRESS_BOOK_SYSTEM_BPTREE_H

#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>

class Node {
    bool IS_LEAF;
    int *key, size;
    Node** ptr;
    Node* parent;
    friend class BPTree;
    static const int MAX = 2;
public:
    Node():key(new int[MAX+1]),ptr(new Node* [MAX+1]),parent(NULL){}
    ~Node(){delete ptr;delete key;};
};

class BPTree {
    Node *root;
    void insertInternal(int,Node*,Node*,Node*);
    void split(int ,Node *,Node *);
    int insertVal(int ,Node *);
    void removeInternal(int, Node *, Node *);
    Node *findParent(Node *, Node *);

public:
    BPTree();
    void insert(int);
    void remove(int);
    void display();
    Node *getRoot();
};

#endif //ADDRESS_BOOK_SYSTEM_BPTREE_H
