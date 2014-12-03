
#ifndef QUEUE_CPP
#define QUEUE_CPP

#include<iostream>

using namespace std;

template <class Pikachu>
Queue<Pikachu>::Queue() {
    array = new Pikachu[40];
    capacity = 40;
    frontIndex = 0;
    endIndex = -1;
}

template <class Pikachu>
Queue<Pikachu>::~Queue() {
    delete [] array;
}

template <class Pikachu>
Pikachu Queue<Pikachu>::front() const {
    if (frontIndex % capacity == (endIndex + 1) % capacity) {
        throw "empty queue!";
    }
    return array[frontIndex];
}

template <class Pikachu>
Pikachu Queue<Pikachu>::dequeue() {
    if (frontIndex == endIndex + 1) {
        throw "empty queue!";
    }
    int oldFront = frontIndex;
    frontIndex = (frontIndex + 1) % capacity;
    return array[oldFront];
}

template <class Pikachu>
void Queue<Pikachu>::enqueue(Pikachu newElement) {
    if ((frontIndex % capacity) == (endIndex + 2)% capacity) {
        resize();
    }
    endIndex = (endIndex + 1) % capacity;
    array[endIndex] = newElement; 
}

template <class Pikachu>
bool Queue<Pikachu>::isEmpty() const {
    if (frontIndex % capacity == (endIndex + 1) % capacity) {
        return true;
    } else {
        return false;
    }
}

template <class Pikachu>
void Queue<Pikachu>::resize() {
    throw "Queue full!";   // stephen is lazy
    // Do the normal copy-into-a-larger-array-then-deallocate-the-old-one
    // thing.
}

#endif
