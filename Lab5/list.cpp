#include <iostream>
using namespace std;

struct Node {
    int data;       // The value stored in the node
    Node* next;     // Pointer to the next node
};

class List { 
public: 
    // Constructor 
    List(void) { head = NULL; } 

    // Destructor 
    ~List(void) {};

    bool isEmpty() { return head == NULL; } 

    // Insert at the given index 
    Node* insertNode(int index, int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;

        if(index == 1) {
            newNode->next = head;
            head = newNode;
            return head;
        }

        Node* temp = head;
        for(int i = 0; i < index - 2; i++) {
            if(temp == nullptr) {
                cout << "Invalid position";
                return head;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    };

    // Insert at start of list 
    Node* insertAtHead(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = head;

        return head = newNode;
    };

    // Insert at end of list 
    Node* insertAtEnd(int x) {
        // Create new node
        Node* newNode = new Node{x, nullptr};

        // If the list is empty, make the new value the head and return it
        if(!head) return head = newNode;

        // Otherwise, go to the last node
        Node* temp = head;
        while (temp->next) 
            temp = temp->next; 

        // Make newNode the last node and return head
        temp->next = newNode;
        return head;
    };

    // Search for data value x in the list 
    bool findNode(int x) {
        // Start from head
        Node* current = head;

        // Go upto to the last element and return true if the value is found, else return false
        while (current != nullptr){
            if (current->data == x) 
                return true;
            current = current->next;
        }
        return false;
    };

    // Delete all occurrences of x
    bool deleteNode(int x) {
        if (!head) return false; // empty list

        bool deleted = false;

        // If head->data = x, delete head
        while (head && head->data == x) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            deleted = true;
        }

        // If list becomes empty after deleting head nodes
        if (!head) return deleted;

        // Handle rest of the list
        Node* temp = head;
        while (temp->next) {
            if (temp->next->data == x) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                deleted = true;
            } else {
                temp = temp->next;
            }
        }
        return deleted;
    }

    // Deletes starting node of list 
    bool deleteFromStart() {
        if (!head) return false;  // list empty, nothing to delete

        // Store and delete the node safelys
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    // Deletes last node of list 
    bool deleteFromEnd() {
        if (!head) return false;  // list empty, nothing to delete
        // Case 1: If there is only one node
        if(head->next == nullptr) {
            delete head;
            head = nullptr;
            return true;
        }

        // Case 2: If more than one nodes
        Node* temp = head;
        while(temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
        return true;
    };

    // Print the list
    void displayList(void) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;
        while(current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }; 

     // Reverses the linklist and returns a new list 
    Node* reverseList() {
        Node *prev, *current, *next;
        current = head;
        prev = nullptr;

        while(current->next != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
        return head;
    };

    // Sorts the input-ed list
    Node* sortList(Node *list) {
        Node* sortedList;

        Node* min = list;
        while(list->next) {
            if(list->data < min->data) {
                min = list
            }
        }
    }; 

    // Removes duplicates from list 
    Node* removeDuplicates(Node *list) {

    };

    // Merges two lists
    Node* mergeLists(Node *list1, Node *list2) {

    }; 

    // Results contains intersection of two lists 
    Node* interestLists(Node *list1, Node *list2) {

    };

private: 
    Node* head; 
};

int main() {

    return 0;
}