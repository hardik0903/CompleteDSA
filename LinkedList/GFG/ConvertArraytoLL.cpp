#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Solution {
public:
    Node* constructLL(vector<int>& arr) {
        if (arr.empty()) {
            return NULL;
        }

        Node* head = new Node(arr[0]);
        Node* temp = head;

        for (int i = 1; i < arr.size(); i++) {
            temp->next = new Node(arr[i]);
            temp = temp->next;
        }

        return head;
    }
};

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data;
        if (current->next != NULL) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    Solution sol;

    vector<int> arr1 = {1, 2, 3, 4, 5};
    cout << "Vector arr1: ";
    for (int x : arr1) {
        cout << x << " ";
    }
    cout << endl;
    Node* head1 = sol.constructLL(arr1);
    cout << "Constructed LL from arr1: ";
    printList(head1);
    cout << "---------------------------------------" << endl;

    return 0;
}