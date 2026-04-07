#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    int *arr;
    int topIndex;
    int capacity;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    // 1. Push
    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++topIndex] = val;
    }

    // 2. Pop
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }
        topIndex--;
    }

    // 3. Top element
    int top() {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
            return -1;
        }
        return arr[topIndex];
    }

    // 4. isEmpty
    bool isEmpty() {
        return topIndex == -1;
    }

    // 5. isFull
    bool isFull() {
        return topIndex == capacity - 1;
    }

    // 6. Size
    int size() {
        return topIndex + 1;
    }

    // 7. Print stack (top to bottom)
    void print() {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // 8. Clear the stack
    void clear() {
        topIndex = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack st(10);

    st.push(5);
    st.push(10);
    st.push(15);
    st.print();  // 15 10 5

    cout << "Top: " << st.top() << endl;

    st.pop();
    st.print();

    cout << "Size: " << st.size() << endl;
    cout << "Empty? " << (st.isEmpty() ? "Yes" : "No") << endl;

    st.clear();
    cout << "After clear -> Empty? " << (st.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
