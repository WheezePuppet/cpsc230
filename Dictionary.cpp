
#include"Dictionary.h"
#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

const char * Dictionary::DICT_FILE = "/usr/share/dict/words";


void Word::insert(std::string word) {
    if (word < this->word) {
        if (left == NULL) {
            left = new Word(word);
        } else {
            left->insert(word);
        }
    } else {
        if (right == NULL) {
            right = new Word(word);
        } else {
            right->insert(word);
        }
    }
}


bool Word::contains(std::string word) const {
    if (word == this->word) {
        return true;
    }
    if (word < this->word) {
        if (left == NULL) {
            return false;
        } else {
            return left->contains(word);
        }
    } else {
        if (right == NULL) {
            return false;
        } else {
            return right->contains(word);
        }
    }
}

Word::Word(std::string word) {
    left = right = NULL;
    this->word = word;
}


void Dictionary::insert(std::string word) {
    if (root == NULL) {
        root = new Word(word);
    } else {
        root->insert(word);
    }
}


bool Dictionary::contains(std::string word) const {
    if (root != NULL) {
        return root->contains(word);
    }
    return false;
}

Dictionary::Dictionary() {

    root = NULL;
    ifstream dictFile(DICT_FILE);

    // Read words into array.
    string words[NUM_WORDS];
    for (int i=0; i<NUM_WORDS; i++) {
        getline(dictFile,words[i]);
    }

    // Shuffle array.
    for (int i=0; i<NUM_WORDS; i++) {
        int r = rand() % NUM_WORDS;
        string tmp = words[i];
        words[i] = words[r];
        words[r] = tmp;
    }
    
    // Insert shuffled words into BST.
    for (int i=0; i<NUM_WORDS; i++) {
        insert(words[i]);
    }
}

