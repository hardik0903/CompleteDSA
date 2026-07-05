#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyNode = new ListNode(-1);
    ListNode* t1 = l1;
    ListNode* t2 = l2;
    ListNode* curr = dummyNode;
    int carry = 0;

    while(t1 != NULL || t2 != NULL){
        int sum = carry;

        if(t1) sum = sum + t1->val;
        if(t2) sum = sum + t2->val;

        ListNode* newNode = new ListNode(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;

        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }

    if(carry){
        ListNode* newNode = new ListNode(carry);
        curr->next = newNode;
    }

    return dummyNode->next;
}

int main() {
    using namespace std;

    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    cout << "List 1: ";
    ListNode* current = l1;
    while (current != NULL) {
        cout << current->val;
        current = current->next;
    }
    cout << endl;

    cout << "List 2: ";
    current = l2;
    while (current != NULL) {
        cout << current->val;
        current = current->next;
    }
    cout << endl;

    ListNode* result = addTwoNumbers(l1, l2);

    cout << "Result: ";
    current = result;
    while (current != NULL) {
        cout << current->val;
        current = current->next;
    }
    cout << endl;

    return 0;
}
