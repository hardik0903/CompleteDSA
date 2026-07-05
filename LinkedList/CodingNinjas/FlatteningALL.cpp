#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

//!BRUTE-FORCE APPROACH
// Node *converttoLL(vector<int> arr)
// {

//     if (arr.empty())
//         return NULL;

//     Node* head = new Node(arr[0]);
//     Node *temp = head;
//     int n=arr.size();

//     for (int i = 1; i < n; i++)
//     {
//         Node* newNode = new Node(arr[i]);
//         temp->child = newNode;
//         temp = temp->child;
//     }
//     return head;
// }

// Node *flattenLL(Node *head)
// {

//     Node *temp = head;
//     vector<int> arr;

//     while (temp != NULL)
//     {
//         Node *t2 = temp;
//         while (t2 != NULL)
//         {
//             arr.push_back(t2->data);
//             t2 = t2->child;
//         }
//         temp = temp->next;
//     }

//     sort(arr.begin(), arr.end());

//     Node* newNode = converttoLL(arr);

//     return newNode;
// }

Node* merge2Lists(Node* list1,Node* list2){
    Node* dummyNode=new Node(-1);
    Node* res=dummyNode;

    while(list1!=NULL && list2!=NULL){
        if(list1->data < list2->data){
            res->child=list1;
            res=list1;
            list1=list1->child;
        }
        else{
            res->child=list2;
            res=list2;
            list2=list2->child;
        }
        res->next=NULL;
    }

    if(list1) res->child=list1;
    else res->child=list2;

    return dummyNode->child;
}

Node* flattenLL(Node* head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* newNode=flattenLL(head->next);

    return merge2Lists(head,newNode);
}


int main()
{
    Node *head = nullptr;

    Node *node5_child = new Node(6);
    node5_child->child = new Node(8);
    Node *node5 = new Node(5, nullptr, node5_child);

    Node *node4_child = new Node(9);
    Node *node4 = new Node(4, node5, node4_child);

    Node *node1_child = new Node(7);
    node1_child->child = new Node(11);
    node1_child->child->child = new Node(12);
    Node *node1 = new Node(1, node4, node1_child);

    Node *node2_child = new Node(10);
    Node *node2 = new Node(2, node1, node2_child);

    Node *node3 = new Node(3, node2, nullptr);

    head = node3;

    Node* ans=flattenLL(head);

    cout<<"Calcula Answer is: ";
    while(ans!=NULL){
        cout<<ans->data<<"->";
        ans=ans->child;
    }
    cout<<"NULL";

    cout<<endl;

    cout<<"Correct Answer is: 1->2->3->4->5->6->7->8->9->10->11->12->NULL";

    return 0;
}
