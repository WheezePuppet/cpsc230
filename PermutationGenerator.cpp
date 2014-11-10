
#include<iostream>
#include<string>
#include"utils.h"
using namespace std;

int fact(int n) {
    if (n ==0) return 1;
    return n * fact(n-1);
}   

void generatePermutations(string word, string permutations[]) {
        
    if (word.length() == 1) {
        permutations[0] = word;
        return;
    }       
        
    int cnt=0;
    for (int i=0; i<word.length(); i++) {
        string shorterword = 
            word.substr(0,i) +
            word.substr(i+1,word.length()-i-1);
        string shorterPerms[fact(word.length()-1)];
        generatePermutations(shorterword, shorterPerms);
        for (int j=0; j<fact(word.length()-1); j++) {
            permutations[cnt++] = word[i] + shorterPerms[j];
        }
    }
}


void printPerms(string word, ostream & os) {

    string perms[fact(word.length())];
    generatePermutations(word, perms);
    for (int i=0; i<fact(word.length()); i++) {
        os << i << ": " << perms[i] << endl;
    }
}
