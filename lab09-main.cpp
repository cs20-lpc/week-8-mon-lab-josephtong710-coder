#include <iostream>
#include "ArrayStack.hpp"
using namespace std;

template <typename T>
void testRotate(ArrayStack<T>& s) {
    cout << "\n-- Before rotate --\n" << s;
    s.rotate(Stack<T>::RIGHT);
    cout << "-- After RIGHT rotate --\n" << s;
    s.rotate(Stack<T>::LEFT);
    cout << "-- After LEFT rotate --\n" << s;
}

int main() {
    ArrayStack<int> s(5);

    // isEmpty
    cout << "isEmpty: " << (s.isEmpty() ? "true" : "false") << endl;

    // push
    cout << "\nPushing 10, 20, 30, 40, 50...\n";
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s;

    // isFull, getLength, getMaxSize
    cout << "isFull: "     << (s.isFull() ? "true" : "false") << endl;
    cout << "getLength: "  << s.getLength()  << endl;
    cout << "getMaxSize: " << s.getMaxSize() << endl;

    // peek
    cout << "\npeek: " << s.peek() << endl;

    // pop
    cout << "\nPopping twice...\n";
    s.pop();
    s.pop();
    cout << s;

    // rotate
    testRotate(s);

    // copy constructor
    cout << "\nCopy constructor:\n";
    ArrayStack<int> s2(s);
    cout << s2;

    // assignment operator
    cout << "Assignment operator:\n";
    ArrayStack<int> s3(5);
    s3 = s;
    cout << s3;

    // clear
    cout << "Calling clear()...\n";
    s.clear();
    cout << s;
    cout << "isEmpty after clear: " << (s.isEmpty() ? "true" : "false") << endl;

    // exception handling
    cout << "\n-- Exception tests --\n";
    try { s.peek(); }
    catch (string& e) { cout << "Caught: " << e << endl; }

    try { s.pop(); }
    catch (string& e) { cout << "Caught: " << e << endl; }

    try {
        ArrayStack<int> tiny(2);
        tiny.push(1); tiny.push(2);
        tiny.push(3);
    }
    catch (string& e) { cout << "Caught: " << e << endl; }

    return 0;
}