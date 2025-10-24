#include <iostream>
#include "stack.h"

using namespace std;

int performOperation(char c, int operand1, int operand2) {
    int num1 = operand1;
    int num2 = operand2;
    int result = 0;

    if (c == '+') result = num1 + num2;
    else if (c == '-') result = num1 - num2;
    else if (c == '*') result = num1 * num2;
    else if (c == '/') {
        if (num2 == 0) cout << "Error: Divide by zero\n";
        result = num1 / num2;
    }

    return result;
}

int prefix(const string& exp) {
    Stack<int> s;
    for(int i = exp.length() - 1; i >= 0; i--) {
        char c = exp[i];
        if(isdigit(c)) {
            s.push(c - '0');
        } else if(c == '+' || c == '-' || c == '*' || c == '/') {
            int operand1 = s.pop();
            int operand2 = s.pop();
            int result = performOperation(c, operand1, operand2);
            s.push(result);
        }
    }
    return s.pop();
}

int main() {

    string exp;
    cout << "Enter the expression: ";
    getline(cin, exp);

    cout << "The result is: " << prefix(exp) << endl;

    return 0;
}