
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
    return clues[i]->unscramble(dict);
}

string JumbleClue::unscramble(const Dictionary & dict) const {
    string unscrambledWord = scrambledWord;
    for (int i=0; i<scrambledWord.length(); i++) {
        unscrambledWord[i] = tolower(unscrambledWord[i]);
    }
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
