// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#include "stack.h"
#include <stdexcept>

Stack::Stack() : capacity(10), count(0) {
    data = new double[capacity];
}

Stack::~Stack() {
    delete[] data;
}

void Stack::push(double value) {
    if (count >= capacity) {
        resize();
    }
    data[count++] = value;
}

double Stack::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    return data[--count];
}

double Stack::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    return data[count - 1];
}

bool Stack::isEmpty() const {
    return count == 0;
}

size_t Stack::size() const {
    return count;
}

void Stack::resize() {
    capacity *= 2;
    double* newData = new double[capacity];
    for (size_t i = 0; i < count; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}
