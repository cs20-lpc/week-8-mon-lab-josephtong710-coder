#include <iostream>
#include "ArrayStack.hpp"
using namespace std;

template <typename T>
void testRotate(ArrayStack<T>& s) {
    s.rotate(Stack<T>::RIGHT);
    s.rotate(Stack<T>::LEFT);
}

int main() {
    // Stack A: push 0-9
    ArrayStack<int> stackA(10);
    for (int i = 0; i < 10; i++) {
        stackA.push(i);
        cout << i << " ";
    }
    cout << endl;

    // isFull
    if (stackA.isFull())
        cout << "Stack A is full!" << endl;

    // getLength
    cout << "Stack A length: " << stackA.getLength() << endl;

    // Copy constructor: Stack B = Stack A
    ArrayStack<int> stackB(stackA);
    cout << "Stack B length: " << stackB.getLength() << endl;

    // push on full stack (exception)
    try {
        stackB.push(99);
    } catch (string& e) {
        cout << e << endl;
    }

    // pop 5 elements from Stack B, printing each
    for (int i = 0; i < 5; i++) {
        cout << "Popping " << stackB.peek() << " from stack B" << endl;
        stackB.pop();
    }
    cout << "Stack B length: " << stackB.getLength() << endl;

    // clear Stack B
    stackB.clear();
    cout << "Stack B is now empty after being cleared" << endl;

    // pop on empty (exception)
    try {
        stackB.pop();
    } catch (string& e) {
        cout << e << endl;
    }

    // peek on empty (exception)
    try {
        stackB.peek();
    } catch (string& e) {
        cout << e << endl;
    }

    // Stack A still intact
    cout << "Stack A length: " << stackA.getLength() << endl;

    // Assignment operator: Stack C = Stack A
    ArrayStack<int> stackC(10);
    stackC = stackA;
    cout << "Stack C length: " << stackC.getLength() << endl;

    return 0;
}