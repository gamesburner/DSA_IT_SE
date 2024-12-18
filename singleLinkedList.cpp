#include <iostream>
#include <string>
using namespace std;

struct StackNode {
    char data;
    StackNode* next;
};

class Stack {
public:
    StackNode* top;

    Stack() { top = nullptr; }

    void push(char c) {
        StackNode* newNode = new StackNode{c, top};
        top = newNode;
    }

    char pop() {
        if (top) {
            char c = top->data;
            StackNode* temp = top;
            top = top->next;
            delete temp;
            return c;
        }
        return '\0';
    }

    char peek() {
        return (top) ? top->data : '\0';
    
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) { // If the character is an operand
            postfix += c;
        } else if (c == '(') { // If the character is '(', push it to stack
            s.push(c);
        } else if (c == ')') { // If the character is ')', pop until '('
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); 
        } else if (isOperator(c)) { 
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
