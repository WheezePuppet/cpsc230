
#ifndef QUEUE_H
#define QUEUE_H

template <class Pikachu>
class Queue {
    public:
        Queue();
        ~Queue();
        Pikachu front() const;
        bool isEmpty() const;
        Pikachu dequeue();
        void enqueue(Pikachu newElement);
    private:
        void resize();
        Pikachu *array;
        int frontIndex, endIndex;
        int capacity;
};

#include"Queue.cpp"

#endif
