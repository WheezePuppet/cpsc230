
#include"Queue.h"
#include<iostream>
#include<cstdlib>

using namespace std;

int main() {
  try {
    Queue<string> names;
    names.enqueue("Theo");
    names.enqueue("Kyle");
    names.enqueue("Elias");
    cout << "The first guy was " << names.dequeue() << endl;
    cout << "The next guy was " << names.dequeue() << endl;
    if (names.isEmpty()) {
        cout << "No more guys!" << endl;
    } else {
        cout << " More guys!" << endl;
    }
    cout << "The next guy was " << names.dequeue() << endl;
    if (names.isEmpty()) {
        cout << "No more guys!" << endl;
    } else {
        cout << " More guys!" << endl;
    }

    Queue<int> q;
    for (int i=0; i<7; i++) {
        q.enqueue(i);
    }
    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    int num=1;
    for (int i=0; i<700; i++) {
        if (rand() % 10 < 2) {
            try {
                cout << q.dequeue() << " ";
            } catch (const char *x) {
                cout << "nm..." << endl;
            }
        } else {
            q.enqueue(num++);
        }
    }
    cout << endl;
  } catch (const char *x) {
        cout << "yikes!! " << x << endl;
  }
}
