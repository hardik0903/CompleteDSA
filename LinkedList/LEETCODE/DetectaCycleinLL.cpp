#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    
    vector<ListNode*> nodes;
    for (int i = 1; i <= 9; ++i) {
        nodes.push_back(new ListNode(i));
        if (i > 1) {
            nodes[i-2]->next = nodes[i-1];
        }
    }
    // Create the cycle: 9 → 3
    nodes[8]->next = nodes[2];

    //? 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9 (9 →3 )

    // Test for cycle
    if (hasCycle(nodes[0])) {
        cout << "Cycle detected in the list.\n";
    } else {
        cout << "No cycle in the list.\n";
    }

    // Note: We cannot safely delete nodes here because of the cycle.
    return 0;
}
