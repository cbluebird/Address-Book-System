//
// Created by crk on 23-4-25.
//
#include "../include/BPTree.h"
int main(){
    BPTree node;
    node.insert(5);
    node.insert(8);
    node.insert(10);
    node.insert(15);
    node.insert(16);
    node.insert(19);
    node.insert(20);
    node.display();
    return 0;
}