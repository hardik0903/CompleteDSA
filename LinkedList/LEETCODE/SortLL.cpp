#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//!NAIVE APPROACH 1
// ListNode* sortList(ListNode* head){
//     ListNode* temp=head;
//     vector<int> arr;

//     while(temp!=NULL){
//         arr.push_back(temp->val);
//         temp=temp->next;
//     }

//     sort(arr.begin(),arr.end());
//     int i=0;
//     temp=head;

//     while(temp!=NULL){
//         temp->val=arr[i];
//         i++;
//         temp=temp->next;
//     }
//     return head;
// }

//!NAIVE APPROACH 2
// ListNode* convertLL(vector<int> arr){
//     int n=arr.size();
//     ListNode* temp=new ListNode();
//     ListNode* head=temp;

//     for(int i=0;i<n;i++){
//         temp->val=arr[i];

//         if(i<n-1){
//             temp->next=new ListNode();
//             temp=temp->next;
//         }
//     }

//     return head;
// }

// ListNode* sortList(ListNode* head){

//     ListNode* temp=head;
//     vector<int> arr;

//     while(temp!=NULL){
//         arr.push_back(temp->val);
//         temp=temp->next;
//     }

//     sort(arr.begin(),arr.end());
//     ListNode* newHead=convertLL(arr);
//     return newHead;
// }


//!OPTIMAL APPROACH
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

ListNode *middleofLL(ListNode *head)
{

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

ListNode *sortList(ListNode *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    ListNode *leftHead = head;
    ListNode *middle = middleofLL(head);
    ListNode *rightHead = middle->next;
    middle->next = NULL;

    leftHead = sortList(leftHead);
    rightHead = sortList(rightHead);

    return mergeTwoSortedLists(leftHead, rightHead);
}

int main()
{
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Original List: ";
    ListNode* temp=head;
    while(temp->next!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<temp->val<<endl;


    ListNode *sortedHead = sortList(head);

    cout << "Sorted List: ";
    while(sortedHead->next!=NULL){
        cout<<sortedHead->val<<"->";
        sortedHead=sortedHead->next;
    }
    cout<<sortedHead->val<<endl;


    return 0;
}
