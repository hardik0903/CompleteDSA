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
    ListNode* findNode(ListNode* head, int n){
        int cnt=1;
        ListNode* temp=head;
        while(temp->next!=NULL){
            if(cnt==n) return temp;
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL || head->next==NULL){
            return head;
        }
        int len=1;
        ListNode* tail=head;

        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }

        if(k%len==0) return head;

        k=k%len;
        tail->next=head;
        ListNode* newTail=findNode(head,len-k);

        head=newTail->next;
        newTail->next=NULL;

        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution sol;
    ListNode* rotatedHead = sol.rotateRight(head, k);

    ListNode* temp = rotatedHead;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
