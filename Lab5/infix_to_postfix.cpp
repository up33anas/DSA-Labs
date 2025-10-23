#include <iostream>
#include "stack.h"
using namespace std;

// Check operator precedence
bool hasHigherOrEqualPrecedence(char c1, char c2) {
    int p1, p2;

    // Assign precedence levels
    if (c1 == '+' || c1 == '-') p1 = 1;
    else if (c1 == '*' || c1 == '/') p1 = 2;
    else p1 = 0;

    if (c2 == '+' || c2 == '-') p2 = 1;
    else if (c2 == '*' || c2 == '/') p2 = 2;
    else p2 = 0;

    return p1 >= p2;
}

// Convert infix to postfix
string infixToPostfix(string exp) {
    Stack s;
    string result = "";

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        // Ignore spaces
        if (c == ' ') continue;

        // Operand (number or variable)
        if (isalnum(c)) {  
            result += c;
        }

        // Opening parenthesis
        else if (c == '(') {
            s.push(string(1, c));
        }

        // Closing parenthesis
        else if (c == ')') {
            // pop and append until '(' is found
            while (!s.isEmpty() && s.peek() != "(") {
                result += s.pop();
            }
            if (!s.isEmpty()) s.pop(); // pop '('
        }

        // Operator
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!s.isEmpty() && s.peek() != "(" && hasHigherOrEqualPrecedence(s.peek()[0], c)) {
                result += s.pop();
            }
            s.push(string(1, c));
        }
    }

    // Pop remaining operators
    while (!s.isEmpty()) result += s.pop();

    return result;
}

// Main
int main() {
    string infix;
    cout << "Enter the infix expression: ";
    getline(cin, infix);

    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}
