#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;
/*  =======================
        Stack Class
    =======================
*/
class Stack
{
private:
    string* arr;
    int capacity;
    int top;
public:
    // Constructor
    Stack(int size = 15) { 
        capacity = size;
        arr = new string[capacity];
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
    void push(string x) {
        if (isFull()) throw overflow_error("Stack Overflow!");
        arr[++top] = x;
    }

    // Pop the top element
    string pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return "";
        }
        return arr[top--];
    }

    // Peek at the top element
    string peek() const {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return "";
        }
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