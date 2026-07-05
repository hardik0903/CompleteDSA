#include <iostream>
using namespace std;

// Definition of doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int d = 0) : data(d), prev(nullptr), next(nullptr) {}
};

// Deletes all occurrences of value k from the doubly linked list
Node* deleteAllOccurrences(Node* head, int k) {
    Node* temp = head;
    while (temp) {
        if (temp->data == k) {
            if (head == temp) {
                head = head->next;
            }
            Node* prevNode = temp->prev;
            Node* nextNode = temp->next;
            if (prevNode) prevNode->next = nextNode;
            if (nextNode) nextNode->prev = prevNode;
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    // Example data
    int values[] = {10, 4, 10, 10, 6, 10};
    int n = sizeof(values) / sizeof(values[0]);
    int k = 10;

    // Build the doubly linked list manually
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        Node* node = new Node(values[i]);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    // Print original list
    cout << "Original list: ";
    for (Node* curr = head; curr; curr = curr->next) {
        cout << curr->data;
        if (curr->next) cout << " <-> ";
    }
    cout << " <-> NULL\n";

    // Delete all occurrences of k
    head = deleteAllOccurrences(head, k);

    // Print resulting list
    cout << "After deleting all occurrences of " << k << ": ";
    for (Node* curr = head; curr; curr = curr->next) {
        cout << curr->data;
        if (curr->next) cout << " <-> ";
    }
    cout << " <-> NULL\n";

    // Clean up remaining nodes
    while (head) {
        Node* next = head->next;
        delete head;
        head = next;
    }
    return 0;
}
