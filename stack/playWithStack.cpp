
#include<iostream>
#include"StackLL.cpp"

using namespace std;

void pop3(Stack<int> x) {
    for (int i=0; i<3; i++) {
        cout << x.pop() << endl;
    }
}

int main()
{
    Stack<Stack<int> > brian;

    Stack<int> bob;
    bob.push(5);
    bob.push(3);
    brian.push(bob);

    cout << "the top element of the top element is: " <<
        brian.pop().pop() << endl;

    Stack<int> s;
    Stack<string> t;
    s.push(2);
    s.push(3);
    s.push(4);
    t.push("seven");
    cout << s.pop() << endl;
    cout << t.pop() << endl;
    s.push(9);
    t.push("eight");
    cout << s.pop() << endl;
    cout << t.top() << endl;
//    s.push((int) t.pop());
s.push(39483);
    cout << s.pop() << endl;
    s.push(s.pop());
    s.push(1);
    pop3(s);
    cout << s.isEmpty() << endl;
    cout << t.isEmpty() << endl;

    return 0;
}
