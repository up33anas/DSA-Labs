#include <iostream>
using namespace std;

struct Node {
    public:
        int data;       // The value stored in the node
        Node* next;     // Pointer to the next node
    Node(int val, Node* nxt = nullptr) : data(val), next(nxt) {}
};


// // Merge sort for lists
// Node* mergeSort(Node* head) {
    
// }

// Linked List class
class List { 
public: 
    // Constructor 
    List(void) { head = NULL; } 

    // Destructor 
    ~List(void) {};

    bool isEmpty() { return head == NULL; } 

    // Insert at the given index 
    Node* insertNode(int index, int x) {
        Node* newNode = new Node(x);
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
        Node* newNode = new Node(x);
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

        while(current != nullptr) {
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
        if(!list || !list->next) return list;

        Node* middle = getMiddle(list);
        Node* nextToMiddle = middle->next;

        middle->next = nullptr;

        Node* left = sortList(list);
        Node* right = sortList(nextToMiddle);

        return mergeLists(left, right);
    };

    // Helper to sort the class’s main list
    void sort() {
        head = sortList(head);
    }

    // Removes duplicates from list 
    Node* removeDuplicates(Node *list) {
        Node* current = this->sortList(list);
        while(current && current->next) {
            if(current->data == current->next->data) {
                Node* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate;
            } else {
                current = current->next;
            }
        }
        return head;
    };

    // Function to merge two sorted lists
    Node* mergeLists(Node *list1, Node *list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        Node* result = nullptr;

        if(list1->data <= list2->data) {
            result = list1;
            result->next = this->mergeLists(list1->next, list2);
        } else {
            result = list2;
            result->next = this->mergeLists(list1, list2->next);    
        }
        return result;
    }

    // Results contains intersection of two lists 
    Node* intersectLists(Node* list1, Node* list2) {
        Node* result = nullptr;
        Node* tail = nullptr;

        for (Node* temp1 = list1; temp1 != nullptr; temp1 = temp1->next) {
            for (Node* temp2 = list2; temp2 != nullptr; temp2 = temp2->next) {
                if (temp1->data == temp2->data) {
                    Node* newNode = new Node(temp1->data);
                    if (!result) {
                        result = newNode;
                        tail = newNode;
                    } else {
                        tail->next = newNode;
                        tail = newNode;
                    }
                    break; // break inner loop, avoid duplicates
                }
            }
        }
        return result;
    }

    void display(Node* node) {
        while (node) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << "\n";
    }

private: 
    Node* head; 

    // Function to find the middle of the linked list
    Node* getMiddle(Node* head) {
        if(!head) return head;

        Node* slow = head;
        Node* fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main() {
    List list1, list2;

    list1.insertAtEnd(4);
    list1.insertAtEnd(2);
    list1.insertAtEnd(8);
    list1.insertAtEnd(6);

    list2.insertAtEnd(1);
    list2.insertAtEnd(2);
    list2.insertAtEnd(8);
    list2.insertAtEnd(9);

    cout << "List 1: ";
    list1.displayList();
    cout << "List 2: ";
    list2.displayList();

    // Sort both
    list1.sort();
    list2.sort();

    cout << "\nSorted List 1: ";
    list1.displayList();
    cout << "Sorted List 2: ";
    list2.displayList();

    // Intersection
    Node* intersect = list1.intersectLists(list1.sortList(list1.sortList(nullptr)), list2.sortList(list2.sortList(nullptr)));

    cout << "\nIntersection: ";
    list1.display(intersect);

    return 0;
}
