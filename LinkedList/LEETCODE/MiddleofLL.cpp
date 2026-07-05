#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleofLL(ListNode* head){

    ListNode* slow=head;
    ListNode* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main() {
    
    // Predefined linked list: 1 -> 2 -> 3 -> 4 -> 5
    vector<int> values = {1, 2, 3, 4, 5};

    // Build the list
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int v : values) {
        ListNode* node = new ListNode(v);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    // Find the middle node
    ListNode* mid = middleofLL(head);

    // Print the result
    if (mid) {
        cout << "Middle node value: " << mid->val << "\n";
    } else {
        cout << "List is empty.\n";
    }

    return 0;
}
