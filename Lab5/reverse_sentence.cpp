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

// Function to reverse the string
string reverseString(string &sentence) {
    if(sentence.empty()) {
        cout << "No input";
        return "";
    }

    Stack st(50);
    string word = "";

    for(char c : sentence) {
        if(c != ' ') {
            word += c;
        } else if(!word.empty()) {
            st.push(word);
            word.clear();
        }
    }

    if(!word.empty()) st.push(word);

    string result = "";
    while(!st.isEmpty()) {
        result += st.pop();
        if(!st.isEmpty()) result += " ";
    }
    return result;
}

int main() {
    string sentence = "";

    cout << "Enter the sentence to reverse: ";
    getline(cin, sentence);

    cout << "Reversed sentence: " << reverseString(sentence) << endl;

    return 0;
}