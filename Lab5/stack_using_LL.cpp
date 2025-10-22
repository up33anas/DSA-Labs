#include <iostream>
#include <stdexcept>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val, Node* nxt = nullptr) : data(val), next(nxt) {}
};

// Stack class
class Stack {
private:
    Node* top;
    int count; // No of elements

public:
    Stack() : top(nullptr), count(0) {}
    ~Stack();

    bool isEmpty() const {
        return top == nullptr;
    }

    bool isFull() const {
        Node* temp = new (nothrow) Node(0);
        if (!temp) return true;
        delete temp;
        return false;
    }

    void push(int x) {
        if (isFull()) throw overflow_error("Stack Overflow!");
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        count++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        count--;
    }

    int peek() const {
        if (isEmpty()) {
            throw underflow_error("Stack is empty!");
        }
        return top->data;
    }

    int size() const {
        return count;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack (top → bottom): ";
        for (Node* temp = top; temp; temp = temp->next) {
            cout << temp->data << " ";
        }
        cout << "\n";
    }
};

// Destructor
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

// Driver
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    s.display();

    cout << "Current size: " << s.size() << endl;

    return 0;
}
