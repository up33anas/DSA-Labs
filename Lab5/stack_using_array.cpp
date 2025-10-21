#include <iostream>
using namespace std;

/*  =======================
        Stack Class
    =======================
*/
class Stack
{
private:
    int* arr;
    int capacity;
    int top;
public:
    // Constructor
    Stack(int size = 15) { 
        capacity = size;
        arr = new int[capacity];
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
    void push(int x) {
        if (isFull()) throw overflow_error("Stack Overflow!");
        arr[++top] = x;
    }

    // Pop the top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        return arr[top--];
    }

    // Peek at the top element
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
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

// Main Function
int main() {
    Stack s(3);

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    s.push(40);
    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    s.display();
    return 0;
}