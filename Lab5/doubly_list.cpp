#include <iostream>
using namespace std;


// Node for Doubly Linked List
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val, DNode* p = nullptr, DNode* n = nullptr)
        : data(val), prev(p), next(n) {}
};


// Doubly Linked List Class
class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList() {}

    bool isEmpty() { return head == nullptr; }

    void insertAtHead(int x) {
        DNode* newNode = new DNode(x, nullptr, head);
        if (head) head->prev = newNode;
        else tail = newNode;
        head = newNode;
    }

    void insertAtEnd(int x) {
        DNode* newNode = new DNode(x, tail, nullptr);
        if (tail) tail->next = newNode;
        else head = newNode;
        tail = newNode;
    }

    bool deleteFromStart() {
        if (!head) return false;
        DNode* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        return true;
    }

    bool deleteFromEnd() {
        if (!tail) return false;
        DNode* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        return true;
    }

    void displayForward() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void displayBackward() {
        DNode* temp = tail;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << "\n";
    }

    bool findNode(int x) {
        DNode* temp = head;
        while (temp) {
            if (temp->data == x) return true;
            temp = temp->next;
        }
        return false;
    }

    void reverseList() {
        DNode* temp = nullptr;
        DNode* current = head;
        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp) head = temp->prev;
    }
};


int main() {

    cout << "\n=== Doubly Linked List ===\n";
    DoublyLinkedList dList;
    dList.insertAtEnd(10);
    dList.insertAtEnd(20);
    dList.insertAtEnd(30);
    dList.displayForward();
    cout << "Reversed: ";
    dList.reverseList();
    dList.displayForward();

    return 0;
}
