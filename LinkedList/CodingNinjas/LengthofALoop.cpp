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

//!NAIVE APPROACH USING HASHING
// int findLoopLength(Node *head){
//     Node* temp=head;
//     int tvalue=1;
//     map<Node*,int> mpp;

//     while(temp!=NULL){
//         if(mpp.find(temp)!=mpp.end()){
//             return tvalue-mpp[temp];
//         }
//         mpp[temp]=tvalue++;
//         temp=temp->next;
//     }
//     return 0;
// }

//!OPTIMAL APPROACH
int findLength(Node* slow,Node* fast){
    int cnt=1;
    fast=fast->next;
    while(slow!=fast){
        cnt++;
        fast=fast->next;
    }
    return cnt;
}

int findLoopLength(Node* head){
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return findLength(slow,fast);
        }
    }
    return 0;
}

int main(){
    vector<int> values = {1, 2, 15, 4, 13, 6, 7, 8, 9};
    vector<Node*> nodes;
    for (int val : values) {
        nodes.push_back(new Node(val));
    }

    for (size_t i = 0; i < nodes.size() - 1; ++i) {
        nodes[i]->next = nodes[i+1];
    }

    nodes[8]->next = nodes[2];

    int loopLength = findLoopLength(nodes[0]);
    cout << "Length of the loop: " << loopLength << endl;

    return 0;
}