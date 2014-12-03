
#include<iostream>

class StackNode {

    friend class Stack;

    public:
        StackNode(int data);
    private:
        int data;
        StackNode *next;
};

class Stack {
    public:
        Stack();
        int top() const;
        int pop();
        void push(int n);
        bool isEmpty() const;
    private:
        StackNode *topNode;
};
