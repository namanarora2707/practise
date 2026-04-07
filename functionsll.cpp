#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // 1. Insert At Head
    void insertAtHead(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    // 2. Insert At Tail
    void insertAtTail(int val) {
        Node* n = new Node(val);

        if (head == nullptr) {
            head = n;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = n;
    }

    // 3. Insert at Position (1-based index)
    void insertAtPosition(int pos, int val) {
        if (pos == 1) {
            insertAtHead(val);
            return;
        }

        Node* n = new Node(val);
        Node* temp = head;

        for (int i = 1; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of range\n";
            return;
        }

        n->next = temp->next;
        temp->next = n;
    }

    // 4. Delete At Head
    void deleteAtHead() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // 5. Delete At Tail
    void deleteAtTail() {
        if (head == nullptr) return;

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // 6. Delete at Position
    void deleteAtPosition(int pos) {
        if (pos == 1) {
            deleteAtHead();
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of range\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // 7. Search
    bool search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    // 8. Length
    int length() {
        int cnt = 0;
        Node* temp = head;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    // 9. Print Linked List
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // 10. Reverse (Iterative)
    void reverseIterative() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    // 11. Reverse (Recursive)
    Node* reverseRecursiveHelper(Node* h) {
        if (h == nullptr || h->next == nullptr) 
            return h;

        Node* newHead = reverseRecursiveHelper(h->next);
        h->next->next = h;
        h->next = nullptr;
        return newHead;
    }

    void reverseRecursive() {
        head = reverseRecursiveHelper(head);
    }
};

int main() {
    LinkedList ll;

    ll.insertAtHead(10);
    ll.insertAtTail(20);
    ll.insertAtTail(30);
    ll.insertAtPosition(2, 15);

    ll.print(); // 10 -> 15 -> 20 -> 30 -> NULL

    ll.deleteAtHead();
    ll.deleteAtTail();
    ll.print(); // 15 -> 20 -> NULL

    cout << "Length: " << ll.length() << endl;

    cout << "Search 20: " << (ll.search(20) ? "Found" : "Not Found") << endl;

    ll.reverseIterative();
    ll.print();

    return 0;
}
