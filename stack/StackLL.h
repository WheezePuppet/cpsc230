
#include<iostream>

template <class Pikachu>
class StackNode {

    public:
        StackNode(Pikachu data);
        Pikachu data;
        StackNode<Pikachu> *next;
};

template <class Pikachu>
class Stack {
    public:
        Stack();
        Pikachu top() const;
        Pikachu pop();
        void push(Pikachu n);
        bool isEmpty() const;
    private:
        StackNode<Pikachu> *topNode;
};
