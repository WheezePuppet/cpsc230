
#include"utils.h"
#include"Dictionary.h"
#include<iostream>
#include<fstream>
#include<cctype>

using namespace std;


class JumbleClue {
    friend class JumblePuzzle;
    public:
        JumbleClue(istream & is);
    private:
        string scrambledWord;
        string blanksAndOhs;
};

class JumblePuzzle {
    public:
        const static int CLUES_PER_PUZZLE = 4;
        JumblePuzzle(istream & is);
        ~JumblePuzzle();
        string getScrambledWord(int i) const;
        string getUnscrambledWord(int i) const;
    private:
        Dictionary dict;
        JumbleClue *clues[CLUES_PER_PUZZLE];
};

JumbleClue::JumbleClue(istream & is) {
    is >> scrambledWord;
    is >> blanksAndOhs;
    is.get();
}

JumblePuzzle::JumblePuzzle(istream & is) {
    for (int i=0; i<CLUES_PER_PUZZLE; i++) {
        clues[i] = new JumbleClue(is);
    }
}

JumblePuzzle::~JumblePuzzle() {
    for (int i=0; i<CLUES_PER_PUZZLE; i++) {
        delete clues[i];
    }
}

string JumblePuzzle::getScrambledWord(int i) const {
    return clues[i]->scrambledWord;
}

string JumblePuzzle::getUnscrambledWord(int i) const {
    string scrambledWord = clues[i]->scrambledWord;
    for (int i=0; i<scrambledWord.length(); i++) {
        scrambledWord[i] = tolower(scrambledWord[i]);
    }
    int numPerms = fact(scrambledWord.length());
    string perms[numPerms];
    generatePermutations(scrambledWord,perms);
    for (int i=0; i<numPerms; i++) {
        if (dict.contains(perms[i])) {
            return perms[i];
        }
    }
    throw "" + scrambledWord + " not unscrambleable!";
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        cerr << "Usage: jumble jumbleFile." << endl;
        return 1;
    }

    ifstream jumbleFile(argv[1], ios_base::in);
    JumblePuzzle puzzle(jumbleFile);
    for (int i=0; i<puzzle.CLUES_PER_PUZZLE; i++) {
        cout << puzzle.getUnscrambledWord(i) << endl;
    }
}
