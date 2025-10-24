
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
    cin >> exp;

    cout << "The result is: " << prefix(exp) << endl;

    return 0;
}