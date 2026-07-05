#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    //! First Reverse Method Uisng recursion
    // ListNode* reverseLL(ListNode* head){

    //     if(head==NULL || head->next==NULL){
    //         return head;
    //     }

    //     ListNode* newHead=reverseLL(head->next);
    //     ListNode* front=head->next;
    //     front->next=head;
    //     head->next=NULL;

    //     return newHead;
    // }

    //! Second Reverse Method Using Iteration 
    ListNode* reverseLL(ListNode* head){
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

    //!Naive Approach
    // bool isPalindrome(ListNode* head){
    //     ListNode* temp=head;
    //     stack<int> st;

    //     while(temp!=NULL){
    //         st.push(temp->val);
    //         temp=temp->next;
    //     }

    //     temp=head;

    //     while(temp!=NULL && !st.empty()){
    //         if(temp->val==st.top()){
    //             temp=temp->next;
    //             st.pop();
    //         }
    //         else{
    //             return false;
    //         }
    //     }

    //     return true;
    // }

    //!OPTIMAL APPROACH
    bool isPalindrome(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* newHead=reverseLL(slow->next);
        ListNode* first=head;
        ListNode* second=newHead;

        while(second!=NULL){
            if(first->val==second->val){
                first=first->next;
                second=second->next;
            }
            else{
                return false;
            }
        }

        second=reverseLL(newHead);

        return true;
    }
};

int main() {
    
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(2);
    head1->next->next->next->next = new ListNode(1);

    Solution sol;
    if (sol.isPalindrome(head1)) {
        cout << "Calculated Solution is: Example 1 is a palindrome";
    } else {
        cout << "Calculated Solution is: Example 1 is not a palindrome";
    }
    cout<<" Whereas Real Solution is : is a Palindrome"<<endl;

    
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(3);
    head2->next->next->next->next = new ListNode(2);
    head2->next->next->next->next->next = new ListNode(1);

    if (sol.isPalindrome(head2)) {
        cout << "Calculated Solution is: Example 2 is a palindrome.";
    } else {
        cout << "Calculated Solution is: Example 2 is not a palindrome.";
    }
    cout<<" Whereas Real Solution is : is a Palindrome"<<endl;

    
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);
    head3->next->next = new ListNode(3);

    if (sol.isPalindrome(head3)) {
        cout << "Calculated Solution is: Example 3 is a palindrome." ;
    } else {
        cout << "Calculated Solution is: Example 3 is not a palindrome.";
    }
    cout<<" Whereas Real Solution is : is not a Palindrome"<<endl;

    return 0;
}