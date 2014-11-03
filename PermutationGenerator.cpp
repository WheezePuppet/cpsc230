
#include<iostream>
#include<string>
using namespace std;

int fact(int n) {
    if (n ==0) return 1;
    return n * fact(n-1);
}   

string *generatePermutations(string word) {
        
    string *permutations = new string[fact(word.length())];

    if (word.length() == 1) {
        permutations[0] = word;
        return permutations; 
    }       
        
    int cnt=0;
    for (int i=0; i<word.length(); i++) {
        string shorterword = 
            word.substr(0,i) +
            word.substr(i+1,word.length()-i-1);
        string *shorterPerms = generatePermutations(shorterword);
        for (int j=0; j<fact(word.length()-1); j++) {
            permutations[cnt++] = word[i] + shorterPerms[j];
        }
    }
    return permutations;
}


int main(int argc, char *argv[]) {

    if (argc < 2) {
        cout << "Usage: PermutationGenerator word." << endl;
        return 1;
    }

    string word = argv[1];
    string *perms = generatePermutations(word);
    for (int i=0; i<fact(word.length()); i++) {
        cout << i << ": " << perms[i] << endl;
    }
}
