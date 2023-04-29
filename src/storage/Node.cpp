//
// Created by crk on 23-4-29.
//

#include "src/include/storage/Node.h"

template<typename KeyType>
Node<KeyType>::Node(){
    key= new KeyType[MAX+1];
    ptr=new Node<KeyType>* [MAX+1];
    page_id=-1;
    size=0;
}