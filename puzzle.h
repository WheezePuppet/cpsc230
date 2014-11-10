
#ifndef PUZZLE_H
#define PUZZLE_H

#include<iostream>
#include"Dictionary.h"

class JumbleClue {
    friend class JumblePuzzle;
    public:
        JumbleClue(std::istream & is);
        string unscramble(const Dictionary & dict) const;
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
    private:
        Dictionary dict;
        JumbleClue *clues[CLUES_PER_PUZZLE];
};

#endif
