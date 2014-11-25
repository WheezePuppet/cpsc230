
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include<string>

using namespace std;

class Word {

    public:
        void insert(string word);
        bool contains(string word) const;
        Word(string word);

    private:
        string word;
        Word *left, *right;
};

class Dictionary {

    const static char * DICT_FILE;
    const static int NUM_WORDS = 98569;
    public:
        void insert(string word);
        bool contains(string word) const;
        Dictionary();

    private:
        Word *root;
};

#endif
