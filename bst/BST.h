
#ifndef BST_H
#define BST_H

#include<string>

using namespace std;

template <class KeyType, class ValueType>
class BSTNode {

    public:
        void insert(KeyType key, ValueType value);
        ValueType getValue(KeyType key) const;
        BSTNode(KeyType key, ValueType value);

    private:
        KeyType key;
        ValueType value;
        BSTNode<KeyType,ValueType> *left, *right;
};

template <class KeyType, class ValueType>
class BST {

    public:
        void insert(KeyType key, ValueType value);
        ValueType getValue(KeyType key) const;
        BST();

    private:
        BSTNode<KeyType,ValueType> *root;
};
#endif
