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

class Solution{
public:

    //!NAIVE APPROACH
    // ListNode* oddEvenList(ListNode* head){
    //     vector<int> arr;

    //     ListNode* temp=head;

    //     if(head==NULL || head->next==NULL){
    //         return head;
    //     }

    //     while(temp!=NULL && temp->next!=NULL){
    //         arr.push_back(temp->val);
    //         temp=temp->next->next;
    //     }
    //     if(temp!=NULL){
    //         arr.push_back(temp->val);
    //     }

    //     temp=head->next;
    //     while(temp!=NULL && temp->next!=NULL){
    //         arr.push_back(temp->val);
    //         temp=temp->next->next;
    //     }
    //     if(temp!=NULL){
    //         arr.push_back(temp->val);
    //     }

    //     int i=0;
    //     temp=head;

    //     while(temp!=NULL){
    //         temp->val=arr[i];
    //         i++;
    //         temp=temp->next;
    //     }

    //     return head;
    // }

    //!OPTIMAL APPROACH
    ListNode* oddEvenList(ListNode* head){
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=head->next;

        if(head==NULL || head->next==NULL){
            return head;
        }

        while(even!=NULL && even->next!=NULL){

            odd->next=odd->next->next;
            even->next=even->next->next;

            odd=odd->next;
            even=even->next;
        }

        odd->next=evenHead;

        return head;
    }
};

int main() {
    using namespace std; // Added using namespace std;

    // Create the linked list: 2->3->1->4->5->6->N
    ListNode* head = new ListNode(2);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    Solution sol;
    ListNode* resultHead = sol.oddEvenList(head);

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
    cout<<"Real Correct Order is:2->1->5->3->4->6->N"<<endl;


    // Clean up memory (optional, but good practice for longer programs)
    current = resultHead;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}