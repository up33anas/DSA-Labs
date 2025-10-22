#include <iostream>
using namespace std;

// Queue Class
class Queue {
private:
    int *arr;
    int front, rear, capacity;

public:
    Queue(int size = 15);
    ~Queue();

    bool isEmpty() const { return (front == -1 && rear == -1); }
    bool isFull()  const { return (rear == capacity - 1); }

    bool enqueue(int x);
    bool dequeue();
    int peek() const;
    void display() const;
};

// Constructor
Queue::Queue(int size) {
    capacity = size;
    arr = new int[capacity];
    front = rear = -1;
}

// Destructor
Queue::~Queue() { delete[] arr; }

// Add element
bool Queue::enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow!\n";
        return false;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    arr[rear] = x;
    return true;
}

// Remove element
bool Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow!\n";
        return false;
    }
    cout << "Removed: " << arr[front] << endl;
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return true;
}

// Peek element
int Queue::peek() const {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return -1;
    }
    return arr[front];
}

// Display elements
void Queue::display() const {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main
int main() {
    Queue q1(3);

    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.display();

    q1.enqueue(4); // Overflow
    q1.dequeue();
    q1.display();

    cout << "Front element: " << q1.peek() << endl;

    return 0;
}
