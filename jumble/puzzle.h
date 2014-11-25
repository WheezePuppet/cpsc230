
#ifndef PUZZLE_H
#define PUZZLE_H

#include<iostream>
#include"Dictionary.h"

extern Dictionary dict;

std::string unscramble_word(const std::string & word);

class JumbleClue {
    friend class JumblePuzzle;
    public:
        JumbleClue(std::istream & is);
        string unscramble() const;
        string getContributingLetters() const;
    private:
        string scrambledWord;
        string blanksAndOhs;
};

class JumblePuzzle {
    public:
        const static int CLUES_PER_PUZZLE = 4;
        JumblePuzzle(std::istream & is);
        ~JumblePuzzle();
        std::string getScrambledWord(int i) const;
        std::string getUnscrambledWord(int i) const;
        std::string getContributingLettersFrom(int i) const;
        std::string getFinalSolution() const;
    private:
        JumbleClue *clues[CLUES_PER_PUZZLE];
        std::string finalQuestion;
        std::string finalAnswer;
};

#endif
