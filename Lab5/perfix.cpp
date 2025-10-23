#include <iostream>
#include "stack.h"

using namespace std;

string performOperation(char c, string operand1, string operand2) {
    int num1 = stoi(operand1);
    int num2 = stoi(operand2);
    int result = 0;

    if (c == '+') result = num1 + num2;
    else if (c == '-') result = num1 - num2;
    else if (c == '*') result = num1 * num2;
    else if (c == '/') {
        if (num2 == 0) return "Error: Divide by zero";
        result = num1 / num2;
    }

    return to_string(result);
}

int prefix(string exp) {
    Stack s;
    for(int i = exp.length() - 1; i >= 0; i--) {
        char c = exp[i];
        if(isdigit(c)) {
            s.push(string(1, c));
        } else if(c == '+' || c == '-' || c == '*' || c == '/') {
            string operand1 = s.pop();
            string operand2 = s.pop();
            string result = performOperation(c, operand1, operand2);
            s.push(result);
        }
    }
    return stoi(s.pop());
}

int main() {

    string exp;
    cout << "Enter the expression: ";
    cin >> exp;

    cout << "The result is: " << prefix(exp) << endl;

    return 0;
}