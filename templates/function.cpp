
#include<iostream>

using namespace std;

template <class Pikachu>
void swapme(Pikachu &x, Pikachu &y) {
    Pikachu tmp = x;
    x = y;
    y = tmp;
}

int main(int argc, char *argv[]) {

    int a=4, b=3;
    cout << "a=" << a << ", b=" << b << endl;
    swapme(a,b);
    cout << "a=" << a << ", b=" << b << endl;
    
    string q="stephen", r="davies";
    cout << "q=" << q << ", r=" << r << endl;
    swapme(q,r);
    cout << "q=" << q << ", r=" << r << endl;
}
