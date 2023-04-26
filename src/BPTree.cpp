//
// Created by crk on 23-4-25.
//

#include "../include/BPTree.h"
#include <queue>

using namespace std;

BPTree::BPTree() { root = NULL; }

int BPTree::insertVal(int x, Node *cursor) {
    int i = 0;
    while (x > cursor->key[i] && i < cursor->size) i++;
    for (int j = cursor->size; j > i; j--) cursor->key[j] = cursor->key[j - 1];
    cursor->key[i] = x;
    cursor->size++;
    return i;
}

void BPTree::insert(int x) {
    if (root == NULL) {
        root = new Node;
        root->key[0] = x;
        root->IS_LEAF = true;
        root->size = 1;
        root->parent = NULL;
    } else {
        Node *cursor = root;
        Node *parent;

        while (cursor->IS_LEAF == false) {
            parent = cursor;
            for (int i = 0; i < cursor->size; i++) {
                if (x < cursor->key[i]) {
                    cursor = cursor->ptr[i];
                    break;
                }

                if (i == cursor->size - 1) {
                    cursor = cursor->ptr[i + 1];
                    break;
                }
            }
        }
        if (cursor->size < Node::MAX) {
            insertVal(x,cursor);
            cursor->parent = parent;
            cursor->ptr[cursor->size] = cursor->ptr[cursor->size - 1];
            cursor->ptr[cursor->size - 1] = NULL;
        } else split(x, parent, cursor);
    }
}

void BPTree::split(int x, Node * parent, Node *cursor) {
    Node* LLeaf=new Node;
    Node* RLeaf=new Node;
    insertVal(x,cursor);
    LLeaf->IS_LEAF=RLeaf->IS_LEAF=true;
    LLeaf->size=(Node::MAX+1)/2;
    RLeaf->size=(Node::MAX+1)-(Node::MAX+1)/2;
    for(int i=0;i<Node::MAX+1;i++)LLeaf->ptr[i]=cursor->ptr[i];
    LLeaf->ptr[LLeaf->size]= RLeaf;
    RLeaf->ptr[RLeaf->size]= LLeaf->ptr[Node::MAX];
    LLeaf->ptr[Node::MAX] = NULL;
    for (int i = 0;i < LLeaf->size; i++) {
        LLeaf->key[i]= cursor->key[i];
    }
    for (int i = 0,j=LLeaf->size;i < RLeaf->size; i++,j++) {
        RLeaf->key[i]= cursor->key[j];
    }
    if(cursor==root){
        Node* newRoot=new Node;
        newRoot->key[0] = RLeaf->key[0];
        newRoot->ptr[0] = LLeaf;
        newRoot->ptr[1] = RLeaf;
        newRoot->IS_LEAF = false;
        newRoot->size = 1;
        root = newRoot;
        LLeaf->parent=RLeaf->parent=newRoot;
    }
    else {insertInternal(RLeaf->key[0],parent,LLeaf,RLeaf);}
}

void BPTree::insertInternal(int x,Node* cursor,Node* LLeaf,Node* RRLeaf)
{

    if (cursor->size < Node::MAX) {
        auto i=insertVal(x,cursor);
        for (int j = cursor->size;j > i + 1; j--) {
            cursor->ptr[j]= cursor->ptr[j - 1];
        }
        cursor->ptr[i]=LLeaf;
        cursor->ptr[i + 1] = RRLeaf;
    }

    else {

        Node* newLchild = new Node;
        Node* newRchild = new Node;
        Node* virtualPtr[Node::MAX + 2];
        for (int i = 0; i < Node::MAX + 1; i++) {
            virtualPtr[i] = cursor->ptr[i];
        }
        int i=insertVal(x,cursor);
        for (int j = Node::MAX + 2;j > i + 1; j--) {
            virtualPtr[j]= virtualPtr[j - 1];
        }
        virtualPtr[i]=LLeaf;
        virtualPtr[i + 1] = RRLeaf;
        newLchild->IS_LEAF=newRchild->IS_LEAF = false;
        //这里和叶子结点上有区别的
        newLchild->size= (Node::MAX + 1) / 2;
        newRchild->size= Node::MAX - (Node::MAX + 1) /2;
        for (int i = 0;i < newLchild->size;i++) {

            newLchild->key[i]= cursor->key[i];
        }
        for (int i = 0, j = newLchild->size+1;i < newRchild->size;i++, j++) {

            newRchild->key[i]= cursor->key[j];
        }
        for (int i = 0;i < LLeaf->size + 1;i++) {
            newLchild->ptr[i]= virtualPtr[i];
        }
        for (int i = 0, j = LLeaf->size + 1;i < RRLeaf->size + 1;i++, j++) {
            newRchild->ptr[i]= virtualPtr[j];
        }
        if (cursor == root) {
            Node* newRoot = new Node;
            newRoot->key[0]= cursor->key[newLchild->size];
            newRoot->ptr[0] = newLchild;
            newRoot->ptr[1] = newRchild;
            newRoot->IS_LEAF = false;
            newRoot->size = 1;
            root = newRoot;
            newLchild->parent=newRchild->parent=newRoot;
        }
        else {
            insertInternal(cursor->key[newLchild->size],cursor->parent,newLchild,newRchild);
        }
    }
}


Node *BPTree::findParent(Node *cursor, Node *child) {
    Node *parent;
    if (cursor->IS_LEAF || (cursor->ptr[0])->IS_LEAF) {
        return NULL;
    }
    for (int i = 0; i < cursor->size + 1; i++) {
        if (cursor->ptr[i] == child) {
            parent = cursor;
            return parent;
        } else {
            parent = findParent(cursor->ptr[i], child);
            if (parent != NULL) return parent;
        }
    }
    return parent;
}

void BPTree::remove(int x) {
    if (root == NULL) {
        cout << "Tree empty\n";
    } else {
        Node *cursor = root;
        Node *parent;
        int leftSibling, rightSibling;
        while (cursor->IS_LEAF == false) {
            for (int i = 0; i < cursor->size; i++) {
                parent = cursor;
                leftSibling = i - 1;
                rightSibling = i + 1;
                if (x < cursor->key[i]) {
                    cursor = cursor->ptr[i];
                    break;
                }
                if (i == cursor->size - 1) {
                    leftSibling = i;
                    rightSibling = i + 2;
                    cursor = cursor->ptr[i + 1];
                    break;
                }
            }
        }
        bool found = false;
        int pos;
        for (pos = 0; pos < cursor->size; pos++) {
            if (cursor->key[pos] == x) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Not found\n";
            return;
        }
        for (int i = pos; i < cursor->size; i++) {
            cursor->key[i] = cursor->key[i + 1];
        }
        cursor->size--;
        if (cursor == root) {
            for (int i = 0; i < Node::MAX + 1; i++) {
                cursor->ptr[i] = NULL;
            }
            if (cursor->size == 0) {
                cout << "Tree died\n";
                delete[] cursor->key;
                delete[] cursor->ptr;
                delete cursor;
                root = NULL;
            }
            return;
        }
        cursor->ptr[cursor->size] = cursor->ptr[cursor->size + 1];
        cursor->ptr[cursor->size + 1] = NULL;
        if (cursor->size >= (Node::MAX + 1) / 2) {
            return;
        }
        if (leftSibling >= 0) {
            Node *leftNode = parent->ptr[leftSibling];
            if (leftNode->size >= (Node::MAX + 1) / 2 + 1) {
                for (int i = cursor->size; i > 0; i--) {
                    cursor->key[i] = cursor->key[i - 1];
                }
                cursor->size++;
                cursor->ptr[cursor->size] = cursor->ptr[cursor->size - 1];
                cursor->ptr[cursor->size - 1] = NULL;
                cursor->key[0] = leftNode->key[leftNode->size - 1];
                leftNode->size--;
                leftNode->ptr[leftNode->size] = cursor;
                leftNode->ptr[leftNode->size + 1] = NULL;
                parent->key[leftSibling] = cursor->key[0];
                return;
            }
        }
        if (rightSibling <= parent->size) {
            Node *rightNode = parent->ptr[rightSibling];
            if (rightNode->size >= (Node::MAX + 1) / 2 + 1) {
                cursor->size++;
                cursor->ptr[cursor->size] = cursor->ptr[cursor->size - 1];
                cursor->ptr[cursor->size - 1] = NULL;
                cursor->key[cursor->size - 1] = rightNode->key[0];
                rightNode->size--;
                rightNode->ptr[rightNode->size] = rightNode->ptr[rightNode->size + 1];
                rightNode->ptr[rightNode->size + 1] = NULL;
                for (int i = 0; i < rightNode->size; i++) {
                    rightNode->key[i] = rightNode->key[i + 1];
                }
                parent->key[rightSibling - 1] = rightNode->key[0];
                return;
            }
        }
        if (leftSibling >= 0) {
            Node *leftNode = parent->ptr[leftSibling];
            for (int i = leftNode->size, j = 0; j < cursor->size; i++, j++) {
                leftNode->key[i] = cursor->key[j];
            }
            leftNode->ptr[leftNode->size] = NULL;
            leftNode->size += cursor->size;
            leftNode->ptr[leftNode->size] = cursor->ptr[cursor->size];
            removeInternal(parent->key[leftSibling], parent, cursor);
            delete[] cursor->key;
            delete[] cursor->ptr;
            delete cursor;
        } else if (rightSibling <= parent->size) {
            Node *rightNode = parent->ptr[rightSibling];
            for (int i = cursor->size, j = 0; j < rightNode->size; i++, j++) {
                cursor->key[i] = rightNode->key[j];
            }
            cursor->ptr[cursor->size] = NULL;
            cursor->size += rightNode->size;
            cursor->ptr[cursor->size] = rightNode->ptr[rightNode->size];
            cout << "Merging two leaf nodes\n";
            removeInternal(parent->key[rightSibling - 1], parent, rightNode);
            delete[] rightNode->key;
            delete[] rightNode->ptr;
            delete rightNode;
        }
    }
}

void BPTree::removeInternal(int x, Node *cursor, Node *child) {
    if (cursor == root) {
        if (cursor->size == 1) {
            if (cursor->ptr[1] == child) {
                delete[] child->key;
                delete[] child->ptr;
                delete child;
                root = cursor->ptr[0];
                delete[] cursor->key;
                delete[] cursor->ptr;
                delete cursor;
                cout << "Changed root node\n";
                return;
            } else if (cursor->ptr[0] == child) {
                delete[] child->key;
                delete[] child->ptr;
                delete child;
                root = cursor->ptr[1];
                delete[] cursor->key;
                delete[] cursor->ptr;
                delete cursor;
                cout << "Changed root node\n";
                return;
            }
        }
    }
    int pos;
    for (pos = 0; pos < cursor->size; pos++) {
        if (cursor->key[pos] == x) {
            break;
        }
    }
    for (int i = pos; i < cursor->size; i++) {
        cursor->key[i] = cursor->key[i + 1];
    }
    for (pos = 0; pos < cursor->size + 1; pos++) {
        if (cursor->ptr[pos] == child) {
            break;
        }
    }
    for (int i = pos; i < cursor->size + 1; i++) {
        cursor->ptr[i] = cursor->ptr[i + 1];
    }
    cursor->size--;
    if (cursor->size >= (Node::MAX + 1) / 2 - 1) {
        return;
    }
    if (cursor == root) return;
    Node *parent = findParent(root, cursor);
    int leftSibling, rightSibling;
    for (pos = 0; pos < parent->size + 1; pos++) {
        if (parent->ptr[pos] == cursor) {
            leftSibling = pos - 1;
            rightSibling = pos + 1;
            break;
        }
    }
    if (leftSibling >= 0) {
        Node *leftNode = parent->ptr[leftSibling];
        if (leftNode->size >= (Node::MAX + 1) / 2) {
            for (int i = cursor->size; i > 0; i--) {
                cursor->key[i] = cursor->key[i - 1];
            }
            cursor->key[0] = parent->key[leftSibling];
            parent->key[leftSibling] = leftNode->key[leftNode->size - 1];
            for (int i = cursor->size + 1; i > 0; i--) {
                cursor->ptr[i] = cursor->ptr[i - 1];
            }
            cursor->ptr[0] = leftNode->ptr[leftNode->size];
            cursor->size++;
            leftNode->size--;
            return;
        }
    }
    if (rightSibling <= parent->size) {
        Node *rightNode = parent->ptr[rightSibling];
        if (rightNode->size >= (Node::MAX + 1) / 2) {
            cursor->key[cursor->size] = parent->key[pos];
            parent->key[pos] = rightNode->key[0];
            for (int i = 0; i < rightNode->size - 1; i++) {
                rightNode->key[i] = rightNode->key[i + 1];
            }
            cursor->ptr[cursor->size + 1] = rightNode->ptr[0];
            for (int i = 0; i < rightNode->size; ++i) {
                rightNode->ptr[i] = rightNode->ptr[i + 1];
            }
            cursor->size++;
            rightNode->size--;
            return;
        }
    }
    if (leftSibling >= 0) {
        Node *leftNode = parent->ptr[leftSibling];
        leftNode->key[leftNode->size] = parent->key[leftSibling];
        for (int i = leftNode->size + 1, j = 0; j < cursor->size; j++) {
            leftNode->key[i] = cursor->key[j];
        }
        for (int i = leftNode->size + 1, j = 0; j < cursor->size + 1; j++) {
            leftNode->ptr[i] = cursor->ptr[j];
            cursor->ptr[j] = NULL;
        }
        leftNode->size += cursor->size + 1;
        cursor->size = 0;
        removeInternal(parent->key[leftSibling], parent, cursor);
    } else if (rightSibling <= parent->size) {
        Node *rightNode = parent->ptr[rightSibling];
        cursor->key[cursor->size] = parent->key[rightSibling - 1];
        for (int i = cursor->size + 1, j = 0; j < rightNode->size; j++) {
            cursor->key[i] = rightNode->key[j];
        }
        for (int i = cursor->size + 1, j = 0; j < rightNode->size + 1; j++) {
            cursor->ptr[i] = rightNode->ptr[j];
            rightNode->ptr[j] = NULL;
        }
        cursor->size += rightNode->size + 1;
        rightNode->size = 0;
        removeInternal(parent->key[rightSibling - 1], parent, rightNode);
    }
}

void BPTree::display() {
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {

        int size_t = q.size();
        while (size_t--) {
            auto t = q.front();
            for (int i = 0; i < t->size + 1; i++) {
                if (!t->IS_LEAF) {
                    q.push(t->ptr[i]);
                }
            }
            for (int i = 0; i < t->size; i++) {
                cout << t->key[i] << ",";
            }
            cout << "  ";
            q.pop();
        }
        cout << endl;

    }
}
Node *BPTree::getRoot() { return root; }
