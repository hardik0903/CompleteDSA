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
    // ListNode* removeNthFromEnd(ListNode* head, int n){

    //     int cnt=0;
    //     ListNode* temp=head;

    //     while(temp!=NULL){
    //         cnt++;
    //         temp=temp->next;
    //     }

    //     if(cnt==n){
    //         ListNode* newHead=head->next;
    //         delete(head);
    //         return newHead;
    //     }
    //     int required=cnt-n;
    //     temp=head;
        
    //     while(temp!=NULL){
    //         required--;
    //         if(required==0){
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;

        for(int i=0;i<n;i++){
            fast=fast->next;
        }

        if(fast==NULL){
            ListNode* newHead=head->next;
            delete(head);
            return newHead;
        }

        ListNode* slow=head;
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
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
    ListNode* resultHead = sol.removeNthFromEnd(head,2);

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
    cout<<"Real Correct Order is:1->2->3->5->N"<<endl;


    // Clean up memory (optional, but good practice for longer programs)
    current = resultHead;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}