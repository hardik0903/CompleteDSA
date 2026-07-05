#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    
    //!NAIVE APPROACH
    // ListNode* deleteMiddle(ListNode* head){

    //     if(head==NULL || head->next==NULL) return NULL;
    //     ListNode* temp=head;
    //     int cnt=0;

    //     while(temp!=NULL){
    //         cnt++;
    //         temp=temp->next;
    //     }

    //     int ms=cnt/2;
    //     temp=head;

    //     while(temp!=NULL){
    //         ms--;
    //         if(ms==0){
    //             break;
    //         }

    //         temp=temp->next;
    //     }

    //     ListNode* delNode=temp->next;
    //     temp->next=temp->next->next;
    //     delete(delNode);

    //     return head;
    // }

    //!OPTIMAL APPROACH
    ListNode* deleteMiddle(ListNode* head){

        if(head==NULL || head->next==NULL) return NULL;

        ListNode* slow=head;
        ListNode* fast=head;

        fast=fast->next->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* delNode=slow->next;
        slow->next=slow->next->next;
        delete(delNode);

        return head;
    }
    
};

int main() {
    using namespace std; // Added using namespace std;

    // Create the linked list: 1->2->3->4->5->N
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* resultHead = sol.deleteMiddle(head);

    // Print the values of the modified list
    ListNode* current = resultHead;
    cout<<"Calculated Order is: ";
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << "->";
        }
        current = current->next;
    }
    cout << "->N" << endl;
    cout<<"Real Correct Order is:1->2->4->5->N"<<endl;


    // Clean up memory (optional, but good practice for longer programs)
    current = resultHead;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}