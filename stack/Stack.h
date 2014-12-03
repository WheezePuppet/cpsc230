
class Stack {
    public:
        Stack();
        int top() const;
        int pop();
        void push(int n);
        bool isEmpty() const;
    private:
        int *array;
        int topIndex;
};
