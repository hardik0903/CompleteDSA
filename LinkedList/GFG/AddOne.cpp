#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

//!ITERATIVE APPROACH(FIRST)
// Node* reverseLL(Node* head){

//     Node* temp=head;
//     Node* prev=NULL;

//     while(temp!=NULL){
//         Node* front=temp->next;
//         temp->next=prev;
//         prev=temp;
//         temp=front;
//     }

//     return prev;
// }

// Node* addOne(Node* head){

//     head=reverseLL(head);
//     Node* temp=head;
//     int carry=1;

//     while(temp!=NULL){
//         temp->data=temp->data+carry;

//         if(temp->data<10){
//             carry=0;
//             break;
//         }
//         else{
//             temp->data=0;
//             carry=1;
//         }

//         temp=temp->next;
//     }

//     if(carry){
//         Node* newNode=new Node(1);
//         head=reverseLL(head);
//         newNode->next=head;
//         return newNode;
//     }

//     head=reverseLL(head);
//     return head;
// }

//!OPTIMAL APPROACH
int helper(Node* temp){

    if(temp==NULL){
        return 1;
    }

    int carry=helper(temp->next);

    temp->data=temp->data+carry;

    if(temp->data<10){
        return 0;
    }

    temp->data=0;
    return 1;
}

Node* addOne(Node* head){

    int carry=helper(head);

    if(carry){
        Node* newNode=new Node(1);
        newNode->next=head;
        return newNode;
    }

    return head;
}

int main() {
    using namespace std;

    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);

    cout << "Original list: ";
    Node* current = head;
    while (current != NULL) {
        cout << current->data;
        current = current->next;
    }
    cout << endl;

    head = addOne(head);

    cout << "List after adding one: ";
    current = head;
    while (current != NULL) {
        cout << current->data;
        current = current->next;
    }
    cout << endl;

    return 0;
}
