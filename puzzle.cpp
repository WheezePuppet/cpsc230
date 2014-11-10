
#include"puzzle.h"
#include"utils.h"
#include<algorithm>

using namespace std;


Dictionary dict;

/////////////////////////////////////////////////////////////////////////////

string tolower(const string & str) {
    string copy = str;
    for (int i=0; i<copy.length(); i++) {
        copy[i] = tolower(copy[i]);
    }
    return copy;
}

/////////////////////////////////////////////////////////////////////////////

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

std::string JumblePuzzle::getContributingLettersFrom(int i) const {
    return clues[i]->getContributingLetters();
}

/////////////////////////////////////////////////////////////////////////////

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

JumbleClue::JumbleClue(istream & is) {
    is >> scrambledWord;
    is >> blanksAndOhs;
    is.get();
}

string JumbleClue::getContributingLetters() const {
    string answer = unscramble();
    int numBlanks = count(blanksAndOhs.begin(), blanksAndOhs.end(), 'O');
    string contributingLetters;
    int contribLetterIndex = blanksAndOhs.find('O');
    while (contribLetterIndex != -1) {
        contributingLetters.append(answer.substr(contribLetterIndex,1));
        contribLetterIndex = blanksAndOhs.find('O',contribLetterIndex+1);
    }
    return contributingLetters;
}
