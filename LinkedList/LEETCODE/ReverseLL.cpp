#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


//!Iterative Method
// ListNode* reverseList(ListNode* head){

//     ListNode* temp=head;
//     ListNode* prev=NULL;

//     while(temp!=NULL){
//         ListNode* front=temp->next;
//         temp->next=prev;
//         prev=temp;
//         temp=front;
//     }
//     return prev;
// }

//!Recursive Method
ListNode* reverseList(ListNode* head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    ListNode* newHead=reverseList(head->next);

    ListNode* front=head->next;
    front->next=head;
    head->next=NULL;

    return newHead;
}

void printList(ListNode* head) {
    for (ListNode* p = head; p; p = p->next) {
        cout << p->val;
        if (p->next) cout << " -> ";
    }
    cout << "\n";
}

int main() {
    // Build a sample list: 1 -> 2 -> 3 -> 4 -> 5
    vector<int> vals = {1, 2, 3, 4, 5};
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

    cout << "Original list: ";
    printList(head);

    head = reverseList(head);
    cout << "Reversed list: ";
    printList(head);


    return 0;
}
