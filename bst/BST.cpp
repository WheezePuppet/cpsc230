
#include"BST.h"
#include<iostream>

using namespace std;


template <class KeyType, class ValueType>
void BSTNode<KeyType,ValueType>::insert(KeyType key, ValueType value) {
    if (key < this->key) {
        if (left == NULL) {
            left = new BSTNode<KeyType,ValueType>(key, value);
        } else {
            left->insert(key, value);
        }
    } else {
        if (right == NULL) {
            right = new BSTNode<KeyType,ValueType>(key, value);
        } else {
            right->insert(key, value);
        }
    }
}

/* Correct version! */
template <class KeyType, class ValueType>
ValueType BSTNode<KeyType,ValueType>::getValue(KeyType key) const {
    if (key == this->key) {
        return this->value;
    }
    if (key < this->key) {
        if (left == NULL) {
            throw exception();
        } else {
            return left->getValue(key);
        }
    } else {
        if (right == NULL) {
            throw exception();
        } else {
            return right->getValue(key);
        }
    }
}

/* BAD version #1 from quiz #6: doesn't (usually) find 
 * the key/value pair it's looking for. 
string BSTNode::getValue(string key) const {
    if (key == this->key) {
        return this->value;
    }
    if (left != NULL) {
        return left->getValue(key);
    }
    if (right != NULL) {
        return right->getValue(key);
    }
    throw exception();
}
*/

/* BAD version #2 from quiz #6: gives correct answer
 * always, but inconceivably slow. 
string BSTNode::getValue(string key) const {
    if (key == this->key) {
        return this->value;
    }
    if (left != NULL) {
        try {
            return left->getValue(key);
        } catch (exception & e) {
        }
    }
    if (right != NULL) {
        try {
            return right->getValue(key);
        } catch (exception & e) {
        }
    }
    throw exception();
}
*/

template <class KeyType, class ValueType>
BSTNode<KeyType,ValueType>::BSTNode(KeyType key, ValueType value) {
    left = right = NULL;
    this->key = key;
    this->value = value;
}


template <class KeyType, class ValueType>
void BST<KeyType,ValueType>::insert(KeyType key, ValueType value) {
    if (root == NULL) {
        root = new BSTNode<KeyType,ValueType>(key, value);
    } else {
        root->insert(key,value);
    }
}


template <class KeyType, class ValueType>
ValueType BST<KeyType,ValueType>::getValue(KeyType key) const {
    if (root != NULL) {
        return root->getValue(key);
    }
    throw exception();
}

template <class KeyType, class ValueType>
BST<KeyType,ValueType>::BST() {
    root = NULL;
}

