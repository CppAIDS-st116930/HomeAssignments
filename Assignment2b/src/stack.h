// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#ifndef STACK_H
#define STACK_H

#include <cstddef>

class Stack {
public:
    Stack();
    ~Stack();

    void push(double value);
    double pop();
    double peek() const;
    bool isEmpty() const;
    size_t size() const;

private:
    double* data;
    size_t capacity;
    size_t count;
    
    void resize();
};

#endif
