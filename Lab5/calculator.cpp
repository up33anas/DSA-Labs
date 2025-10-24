#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

// Function to perform arithmetic operations
int performOperation(int a, int b, const string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return a / b;
    }
    if (op == "%") {
        if (b == 0) {
            cout << "Error: Mod by zero!" << endl;
            return 0;
        }
        return a % b;
    }
    return 0;
}

// Function to print stack content
void printStack(stack<int> s) {
    cout << "Stack (top -> bottom): ";
    if (s.empty()) {
        cout << "Empty" << endl;
        return;
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> stk;
    string input;

    cout << "Postfix Calculator\n";
    cout << "Enter integers or operators (+, -, *, /, %)\n";
    cout << "Use '?' to show stack, '^' to pop and print top, '!' to exit.\n";

    while (true) {
        cout << "> ";
        cin >> input;

        // Exit command
        if (input == "!") {
            cout << "Exiting calculator..." << endl;
            break;
        }

        // Print entire stack
        else if (input == "?") {
            printStack(stk);
        }

        // Pop and print top element
        else if (input == "^") {
            if (!stk.empty()) {
                cout << "Top element: " << stk.top() << endl;
                stk.pop();
            } else {
                cout << "Stack is empty!" << endl;
            }
        }

        // If input is operator
        else if (input == "+" || input == "-" || input == "*" || input == "/" || input == "%") {
            if (stk.size() < 2) {
                cout << "Error: Not enough operands on stack." << endl;
                continue;
            }
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            int result = performOperation(a, b, input);
            stk.push(result);
            cout << "Result pushed: " << result << endl;
        }

        // If input is integer
        else {
            stringstream ss(input);
            int num;
            if (ss >> num) {
                stk.push(num);
            } else {
                cout << "Invalid input: " << input << endl;
            }
        }
    }

    return 0;
}
