
#include"StackLL.h"

template <class Pikachu>
Stack<Pikachu>::Stack() {
    topNode = NULL;
}

template <class Pikachu>
Pikachu Stack<Pikachu>::top() const {
    return topNode->data;
}

template <class Pikachu>
Pikachu Stack<Pikachu>::pop() {
    StackNode<Pikachu> *tmp = topNode;
    Pikachu data = tmp->data;
    topNode = topNode->next;
    tmp->next = NULL;
    delete tmp;
    return data;
}

template <class Pikachu>
void Stack<Pikachu>::push(Pikachu n) {
    StackNode<Pikachu> *tmp = topNode;
    topNode = new StackNode<Pikachu>(n);
    topNode->next = tmp;
}

template <class Pikachu>
bool Stack<Pikachu>::isEmpty() const {
    return topNode == NULL;
}

template <class Pikachu>
StackNode<Pikachu>::StackNode(Pikachu data) {
    this->data = data;
    next = NULL;
}
