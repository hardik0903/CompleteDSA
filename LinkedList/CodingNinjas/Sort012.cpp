#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//!NAIVE APPROACH
// Node* sort012(Node* head){

//     int cnt0=0;
//     int cnt1=0;
//     int cnt2=0;

//     Node* temp=head;
    
//     while(temp!=NULL){

//         if(temp->data==0){
//             cnt0++;
//         }
//         else if(temp->data==1){
//             cnt1++;
//         }
//         else{
//             cnt2++;
//         }
//         temp=temp->next;
//     }

//     temp=head;

//     while(temp!=NULL){

//         if(cnt0){
//             temp->data=0;
//             cnt0--;
//         }
//         else if(cnt1){
//             temp->data=1;
//             cnt1--;
//         }
//         else{
//             temp->data=2;
//             cnt2--;
//         }

//         temp=temp->next;
//     }

//     return head;

// }

//!OPTIMAL APPROACH
Node* sort012(Node* head){

    Node* zeroHead=new Node(-1);
    Node* oneHead=new Node(-1);
    Node* twoHead=new Node(-1);

    Node* zero=zeroHead;
    Node* one=oneHead;
    Node* two=twoHead;

    Node* temp=head;

    while(temp!=NULL){

        if(temp->data==0){
            zero->next=temp;
            zero=temp;
        }
        else if(temp->data==1){
            one->next=temp;
            one=temp;
        }
        else{
            two->next=temp;
            two=temp;
        }

        temp=temp->next;
    }

    zero->next=(oneHead->next) ? oneHead->next : twoHead->next;
    one->next=twoHead->next;
    two->next=NULL;

    Node* newHead=zeroHead->next;

    delete(zeroHead);
    delete(oneHead);
    delete(twoHead);

    return newHead;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    Node* node1 = new Node(1);
    head = node1;
    tail = node1;

    Node* node2 = new Node(0);
    tail->next = node2;
    tail = node2;

    Node* node3 = new Node(2);
    tail->next = node3;
    tail = node3;

    Node* node4 = new Node(1);
    tail->next = node4;
    tail = node4;

    Node* node5 = new Node(0);
    tail->next = node5;
    tail = node5;

    Node* node6 = new Node(2);
    tail->next = node6;
    tail = node6;

    Node* node7 = new Node(1);
    tail->next = node7;
    tail = node7;

    Node* node8 = new Node(0);
    tail->next = node8;
    tail = node8;

    cout << "Original Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    head = sort012(head);

    cout << "Sorted Linked List: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    delete head;

    return 0;
}