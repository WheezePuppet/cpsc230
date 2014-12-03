
#include<iostream>
#include"StackLL.h"

using namespace std;

void pop3(Stack x) {
    for (int i=0; i<3; i++) {
        cout << x.pop() << endl;
    }
}

main()
{
    Stack s;
    Stack t;
    s.push(2);
    s.push(3);
    s.push(4);
    t.push(7);
    cout << s.pop() << endl;
    cout << t.pop() << endl;
    s.push(9);
    t.push(8);
    cout << s.pop() << endl;
    cout << t.top() << endl;
    s.push(t.pop());
    cout << s.pop() << endl;
    s.push(s.pop());
    s.push(1);
    pop3(s);
    cout << s.isEmpty() << endl;
    cout << t.isEmpty() << endl;
}
