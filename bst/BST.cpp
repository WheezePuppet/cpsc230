
#include"BST.h"
#include<iostream>

using namespace std;

void BSTNode::insert(string key, string value) {
    if (key < this->key) {
        if (left == NULL) {
            left = new BSTNode(key, value);
        } else {
            left->insert(key, value);
        }
    } else {
        if (right == NULL) {
            right = new BSTNode(key, value);
        } else {
            right->insert(key, value);
        }
    }
}

/* Correct version! */
string BSTNode::getValue(string key) const {
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

BSTNode::BSTNode(string key, string value) {
    left = right = NULL;
    this->key = key;
    this->value = value;
}


void BST::insert(string key, string value) {
    if (root == NULL) {
        root = new BSTNode(key, value);
    } else {
        root->insert(key,value);
    }
}


string BST::getValue(string key) const {
    if (root != NULL) {
        return root->getValue(key);
    }
    throw exception();
}

BST::BST() {
    root = NULL;
}

