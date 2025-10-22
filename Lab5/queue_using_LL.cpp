#include <iostream>
using namespace std;

// Node Class
struct Node {
    public:
        int data;
        Node* next;
    Node(int val, Node* nxt = nullptr) : data(val), next(nxt) {}
};

// Queue Class
class Queue {
private:
    Node *front, *rear;
public:
    Queue();
    ~Queue();

    bool isEmpty() const { return (front == nullptr && rear == nullptr); }

    bool isFull() const;
    bool enqueue(int x);
    bool dequeue();
    int peek() const;
    void display() const;
};

// Constructor
Queue::Queue() {
    front = rear = nullptr;
}

// Destructor
Queue::~Queue() {
    while(!isEmpty()) dequeue();
}

// Check if queue is full
bool Queue::isFull() const {
    Node* test = new (nothrow) Node(0);
    if (!test) return true;
    delete test;
    return false;
}

// Add element
bool Queue::enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow!\n";
        return false;
    }

    Node* newNode = new Node(x);
    if(isEmpty()) {
        front = rear = newNode;
    } else {
    rear->next = newNode;
    rear = newNode;
    }
    return true;
}

// Remove element
bool Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow!\n";
        return false;
    }

    Node* temp = front;

    if (front == rear) front = rear = nullptr;
    else front = front->next;

    delete temp;
    return true;
}

// Peek element
int Queue::peek() const {
    if (isEmpty()) {
        throw underflow_error("Queue is empty!");
    }
    return front->data;
}

// Display elements
void Queue::display() const {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Queue elements: ";
    for (Node* current = front; current != nullptr; current = current->next)
        cout << current->data << " ";
    cout << endl;
}

int main() {
    Queue q1;

    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);

    q1.display();

    q1.enqueue(4);
    q1.dequeue();

    q1.display();

    cout << "Front element: " << q1.peek() << endl;

    return 0;
}