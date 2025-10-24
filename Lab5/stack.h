#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;
/*  =======================
        Stack Class
    =======================
*/

template <typename T>
class Stack
{
private:
    T* arr;
    int capacity;
    int top;
public:
    // Constructor
    Stack(int size = 15) { 
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Check if stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() const {
        return top == capacity - 1;
    }

    // Push an element onto the stack
    void push(T x) {
        if (isFull()) throw overflow_error("Stack Overflow!");
        arr[++top] = x;
    }

    // Pop the top element
    T pop() {
        if (isEmpty()) throw underflow_error("Stack Underflow!");
        return arr[top--];
    }

    // Peek at the top element
    T peek() const {
        if (isEmpty()) throw underflow_error("Stack is empty");
        return arr[top];
    }

    // Return number of elements in stack
    int size() const {
        return top + 1;
    }

    // Display all elements
    void display() const {
        if (isEmpty()) throw underflow_error("Stack is empty!");

        cout << "Stack elements (bottom --> top): ";
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

#endif