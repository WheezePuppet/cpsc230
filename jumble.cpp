
#include"utils.h"
#include"puzzle.h"
#include"Dictionary.h"
#include<iostream>
#include<fstream>
#include<cctype>

using namespace std;


int main(int argc, char *argv[]) {

    if (argc < 2) {
        cerr << "Usage: jumble jumbleFile." << endl;
        return 1;
    }

    try {
        ifstream jumbleFile(argv[1], ios_base::in);
        JumblePuzzle puzzle(jumbleFile);
        for (int i=0; i<puzzle.CLUES_PER_PUZZLE; i++) {
            cout << puzzle.getUnscrambledWord(i) << endl;
        }
    } catch (const string & msg) {
        cout << "Caught: " << msg << endl;
    }
}
