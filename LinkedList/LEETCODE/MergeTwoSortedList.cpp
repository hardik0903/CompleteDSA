#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoSortedLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummyNode = new ListNode(-1);
    ListNode *temp = dummyNode;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }

    if (list1)
        temp->next = list1;
    else
        temp->next = list2;

    return dummyNode->next;
}

int main()
{
    ListNode *list11 = new ListNode(1);
    ListNode* list1=list11;
    list11->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode *list22 = new ListNode(2);
    ListNode* list2=list22;
    list22->next = new ListNode(4);
    list22->next->next = new ListNode(6);
    
    cout << "List 1: ";
    ListNode* temp1=list1;
    while(temp1->next!=NULL){
        cout<<temp1->val<<"->";
        temp1=temp1->next;
    }
    cout<<temp1->val<<endl;

    cout << "List 2: ";
    ListNode* temp2=list2;
    while(temp2->next!=NULL){
        cout<<temp2->val<<"->";
        temp2=temp2->next;
    }
    cout<<temp2->val<<endl;

    ListNode *sortedHead = mergeTwoSortedLists(list1, list2);
    cout << "Merged List: ";
    while(sortedHead->next!=NULL){
        cout<<sortedHead->val<<"->";
        sortedHead=sortedHead->next;
    }
    cout<<sortedHead->val<<endl;

}