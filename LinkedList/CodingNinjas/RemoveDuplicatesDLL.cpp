#include <iostream>
using namespace std;

// Definition of doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int data = 0) : data(data), prev(nullptr), next(nullptr) {}
};

// Remove duplicates from sorted doubly linked list
Node* removeDuplicates(Node* head) {
    Node* temp = head->next;

    while (temp != nullptr) {
        Node* prevNode = temp->prev;
        Node* nextNode = temp->next;

        if (temp->data == prevNode->data) {
            prevNode->next = nextNode;
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
    // Sorted list: 1 <-> 2 <-> 2 <-> 3 <-> 3 <-> 3 <-> 4
    int vals[] = {1, 2, 2, 3, 3, 3, 4};
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int v : vals) {
        Node* node = new Node(v);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    head = removeDuplicates(head);

    // Print the list after removing duplicates
    Node* curr = head;
    while (curr) {
        cout << curr->data;
        if (curr->next) cout << " <-> ";
        curr = curr->next;
    }
    cout << " <-> NULL\n";

    // Clean up memory
    while (head) {
        Node* next = head->next;
        delete head;
        head = next;
    }

    return 0;
}
