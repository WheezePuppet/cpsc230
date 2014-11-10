
#include"utils.h"
#include"Dictionary.h"
#include<iostream>
#include<fstream>

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
    const static int CLUES_PER_PUZZLE = 4;
    public:
        JumblePuzzle(istream & is);
        ~JumblePuzzle();
        string getScrambledWord(int i) const;
    private:
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

int main(int argc, char *argv[]) {

    if (argc < 2) {
        cerr << "Usage: jumble jumbleFile." << endl;
        return 1;
    }

    ifstream jumbleFile(argv[1], ios_base::in);
    JumblePuzzle puzzle(jumbleFile);
    Dictionary dict;
//    printPerms(puzzle.getScrambledWord(0),cout);
}
