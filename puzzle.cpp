
#include"puzzle.h"
#include"utils.h"

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
