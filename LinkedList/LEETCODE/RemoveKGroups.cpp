#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class
class Solution {
public:
    ListNode* getKthNode(ListNode* temp, int k) {
        while (temp != NULL && --k > 0) {
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseLL(ListNode* head) {
        if(head==NULL || head->next==NULL){
        return head;
    }

    ListNode* newHead=reverseLL(head->next);

    ListNode* front=head->next;
    front->next=head;
    head->next=NULL;

    return newHead;
        
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=NULL;

        while(temp!=NULL){
            ListNode* kth=getKthNode(temp,k);

            if(kth==NULL){
                if(prevNode!=NULL){
                    prevNode->next=temp;
                }
                break;
            }

            ListNode* nextNode=kth->next;
            kth->next=NULL;

            ListNode* newHead=reverseLL(temp);

            if(head==temp) head=kth;
            else prevNode->next=kth;

            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};

int main() {
    // Manually creating linked list: 1 → 2 → 3 → 4 → 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    Solution sol;
    ListNode* newHead = sol.reverseKGroup(head, k);

    // Manually print the result
    ListNode* temp = newHead;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
