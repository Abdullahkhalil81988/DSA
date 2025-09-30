#include <iostream>
#include <string>
using namespace std;

// Stack implementation using arrays
class Stack {
private:
    char arr[1000];  // fixed size for simplicity
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }

    bool isFull() { return top == 999; }

    void push(char c) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (isEmpty()) {
            return '\0'; // return null char if empty
        }
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) return '\0';
        return arr[top];
    }
};

// Function to check if two brackets match
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check balanced expression
bool checkBalanced(string expr) {
    Stack s;
    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];

        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (s.isEmpty()) {
                cout << "This expression is NOT correct e.g. error at character # "
                     << i + 1 << ". '" << c << "' - no matching opening.\n";
                return false;
            }
            char top = s.pop();
            if (!isMatchingPair(top, c)) {
                cout << "This expression is NOT correct e.g. error at character # "
                     << i + 1 << ". '" << top << "' - not closed properly.\n";
                return false;
            }
        }
    }

    if (!s.isEmpty()) {
        cout << "This expression is NOT correct. Some opening bracket(s) not closed.\n";
        return false;
    }

    cout << "This expression is correct.\n";
    return true;
}

int main() {
    string expr;

    cout << "Enter an expression: ";
    getline(cin, expr);

    checkBalanced(expr);

    return 0;
}
