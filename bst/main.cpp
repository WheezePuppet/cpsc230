
#include"BST.h"
#include"LL.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {

    BST testBST;
    LL testLL;

    cout << "Building BST and LL..." << endl;

    char keyS[100];
    for (int i=0; i<5000000; i++) {

        int key = rand();
        sprintf(keyS,"%d",key);

        testBST.insert(keyS, keyS);
        testLL.insert(keyS, keyS);

        if (i % 100000 == 0) {
            cout << "Key #" << i << " is: " << keyS << endl;
        }
    }

    cout << "Press ENTER to search the BST for 1000 elements.";
    cin.get();
    string value;

    for (int i=0; i<1000; i++) {
        int r = rand();
        char searchS[100]; 
        sprintf(searchS,"%d",r);
        if (i%10 == 0) {
            cout << i << " Searching for " << r << "..." << endl;
        }
        try {
            value = testBST.getValue(searchS);
            // Try using testLL here instead and see the diff!
            // value = testLL.getValue(searchS);
            cout << "Found " << value << "!" << endl;    
        } catch (string str) {
        }
    }
}
