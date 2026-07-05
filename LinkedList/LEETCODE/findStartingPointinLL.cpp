#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {

            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return NULL;
}

int main()
{

    vector<ListNode *> nodes;
    for (int i = 1; i <= 9; ++i)
    {
        nodes.push_back(new ListNode(i));
        if (i > 1)
        {
            nodes[i - 2]->next = nodes[i - 1];
        }
    }
    // Create the cycle: 9 → 3
    nodes[8]->next = nodes[2];

    //? 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9 (9 →3 )

    // Test for cycle
    ListNode* ans=detectCycle(nodes[0]);
    if (ans != NULL)
    {
        cout << "Starting Node is: "<<ans->val<<endl;
    }
    else
    {
        cout << "No cycle in the list.\n";
    }

    return 0;
}
