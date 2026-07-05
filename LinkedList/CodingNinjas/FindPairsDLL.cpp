#include <iostream>
#include <vector>
using namespace std;

// Definition of doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int d = 0) : data(d), prev(nullptr), next(nullptr) {}
};

// Two‐pointer search for all pairs in a sorted DLL that sum to k
vector<pair<int,int>> findPairs(Node* head, int k) {
    vector<pair<int,int>> ans;
    if (!head || !head->next) return ans;

    Node* start = head;
    Node* end = head;
    while (end->next) end = end->next;

    while (start != end && start->prev != end) {
        int sum = start->data + end->data;
        if (sum == k) {
            ans.emplace_back(start->data, end->data);
            start = start->next;
            end   = end->prev;
        }
        else if (sum > k) {
            end = end->prev;
        }
        else {
            start = start->next;
        }
    }
    return ans;
}

int main() {
    // Build the list: 1 <-> 2 <-> 3 <-> 4 <-> 9
    int vals[] = {1, 2, 3, 4, 9};
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

    int k = 5;
    auto pairs = findPairs(head, k);

    // Print the pairs
    for (auto &pr : pairs) {
        cout << pr.first << " " << pr.second << "\n";
    }

    // Clean up
    while (head) {
        Node* nxt = head->next;
        delete head;
        head = nxt;
    }
    return 0;
}
