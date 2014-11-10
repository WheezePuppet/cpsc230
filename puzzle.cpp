
#include"puzzle.h"
#include"utils.h"
#include<algorithm>
#include<string>

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

string unscramble_word(const string & word) {
    string unscrambledWord = word;
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

/////////////////////////////////////////////////////////////////////////////

JumblePuzzle::JumblePuzzle(istream & is) {
    for (int i=0; i<CLUES_PER_PUZZLE; i++) {
        clues[i] = new JumbleClue(is);
    }
    getline(is, finalQuestion);
    getline(is, finalAnswer);
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

std::string JumblePuzzle::getFinalSolution() const {
    string finalWord;
    for (int i=0; i<CLUES_PER_PUZZLE; i++) {
        finalWord += clues[i]->getContributingLetters();
    }
    finalWord = unscramble_word(finalWord);
    string solvedAnswer = finalAnswer;
    solvedAnswer.replace(finalAnswer.find('_'), finalWord.length(), finalWord);
    return finalQuestion + "\n" + solvedAnswer;
}


/////////////////////////////////////////////////////////////////////////////

string JumbleClue::unscramble() const {
    return unscramble_word(scrambledWord);
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
