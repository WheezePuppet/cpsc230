
#include"StackLL.h"

Stack::Stack() {
    topNode = NULL;
}

int Stack::top() const {
    return topNode->data;
}

int Stack::pop() {
    StackNode *tmp = topNode;
    int data = tmp->data;
    topNode = topNode->next;
    tmp->next = NULL;
    delete tmp;
    return data;
}

void Stack::push(int n) {
    StackNode *tmp = topNode;
    topNode = new StackNode(n);
    topNode->next = tmp;
}

bool Stack::isEmpty() const {
    return topNode == NULL;
}

StackNode::StackNode(int data) {
    this->data = data;
    next = NULL;
}
