
#include"Stack.h"

int Stack::pop() {
    return array[topIndex--];
}

void Stack::push(int n) {
    array[++topIndex] = n;
}

int Stack::top() const {
    return array[topIndex];
}

Stack::Stack() {
    array = new int[100];
    topIndex = -1;
}

bool Stack::isEmpty() const {
    return topIndex == -1;
}
