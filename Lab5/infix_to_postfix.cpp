#include <iostream>
#include <cctype>
#include <string>
#include "stack.h"
using namespace std;

// Check operator precedence
bool hasHigherOrEqualPrecedence(char c1, char c2) {
    int p1, p2;

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
    Stack<string> s;
    string result = "";

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        // Ignore spaces
        if (c == ' ') continue;

        // Operand (letter or number)
        if (isalnum(c)) {  
            result += c;
        }
        // Opening parenthesis
        else if (c == '(') {
            s.push(string(1, c));
        }
        // Closing parenthesis
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != "(") {
                result += s.pop();
            }
            if (!s.isEmpty()) s.pop(); // pop '('
        }
        // Operator
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Append the result with the stack values until the top operator has higher precedence than the current one 
            while (!s.isEmpty() && s.peek() != "(" && hasHigherOrEqualPrecedence(s.peek()[0], c)) {
                result += s.pop();
            }
            s.push(string(1, c));
        }
    }

    // Pop remaining operators
    while (!s.isEmpty()) {
        result += s.pop();
    }

    return result;
}

// Main function
int main() {
    string infix;
    cout << "Enter the infix expression: ";
    getline(cin, infix);

    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}
