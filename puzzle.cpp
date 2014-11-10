
#include"puzzle.h"
#include"utils.h"

using namespace std;


Dictionary dict;

string tolower(const string & str) {
    string copy = str;
    for (int i=0; i<copy.length(); i++) {
        copy[i] = tolower(copy[i]);
    }
    return copy;
}

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
    return clues[i]->unscramble();
}

string JumbleClue::unscramble() const {
    string unscrambledWord = scrambledWord;
    unscrambledWord = tolower(unscrambledWord);
    int numPerms = fact(unscrambledWord.length());
    string perms[numPerms];
    generatePermutations(unscrambledWord,perms);
    for (int i=0; i<numPerms; i++) {
        if (dict.contains(perms[i])) {
            return perms[i];
        }
    }
    throw "" + unscrambledWord + " not unscrambleable!";
}
