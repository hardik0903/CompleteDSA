#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node){
    ListNode* nxt=node->next;
    node->val=nxt->val;
    node->next=nxt->next;

    delete(nxt);
}

int main() {
    // Build the list: 4 -> 5 -> 1 -> 9
    vector<int> vals = {4, 5, 1, 9};
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int v : vals) {
        ListNode* node = new ListNode(v);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    // Find the node with value 5 
    ListNode* cur = head;
    while (cur && cur->val != 5) {
        cur = cur->next;
    }

    if (cur && cur->next) {
        deleteNode(cur);
        cout << "Deleted successfully.\n";

    } else {
        cout << "Cannot delete the specified node.\n";
    }

    return 0;
}