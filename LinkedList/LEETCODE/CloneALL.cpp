#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:

    //!BRUTE FORCE APPROACH
    // Node* copyRandomList(Node* head){
    //     Node* temp=head;
    //     map<Node*,Node*> mpp;
    //     while(temp!=NULL){
    //         Node* newNode=new Node(temp->val);
    //         mpp[temp]=newNode;
    //         temp=temp->next;
    //     }

    //     temp=head;

    //     while(temp!=NULL){
    //         Node* copyNode=mpp[temp];
    //         copyNode->next=mpp[temp->next];
    //         copyNode->random=mpp[temp->random];
    //         temp=temp->next;
    //     }
    //     return mpp[head];
    // }


    //!OPTIMAL APPROACH
    // Step 1: Inserting in Between
    Node* insertBetween(Node* head){
        Node* temp=head;

        while(temp!=NULL){
            Node* copyNode=new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=temp->next->next;
        }
        return head;
    }

    // Step 2: Connecting Random Pointers
    Node* connectRandom(Node* head){
        Node* temp=head;

        while(temp!=NULL){
            Node* copyNode=temp->next;

            if(temp->random) copyNode->random=temp->random->next;
            else copyNode->random=nullptr;

            temp=temp->next->next;
        }
        return head;
    }

    // Step 3: Connecting Next Pointers
    Node* connectNext(Node* head){
        Node* dummyNode=new Node(-1);
        Node* res=dummyNode;
        Node* temp=head;

        while(temp!=NULL){
            res->next=temp->next;
            temp->next=temp->next->next;
            res=res->next;
            temp=temp->next;
        }
        return dummyNode->next;
    } 
    Node* copyRandomList(Node* head) {
        insertBetween(head);
        connectRandom(head);
        return connectNext(head);
    }
};

int main() {
    Node* node7 = new Node(7);
    Node* node13 = new Node(13);
    Node* node11 = new Node(11);
    Node* node10 = new Node(10);
    Node* node1 = new Node(1);

    node7->next = node13;
    node13->next = node11;
    node11->next = node10;
    node10->next = node1;
    node1->next = NULL;

    node7->random = NULL;
    node13->random = node7;
    node11->random = node1;
    node10->random = node11;
    node1->random = node7;

    Node* head = node7;

    cout << "Original List:" << endl;
    Node* current_original = head;
    map<Node*, int> original_node_idx;
    int idx = 0;
    Node* temp_for_idx = head;
    while(temp_for_idx != NULL) {
        original_node_idx[temp_for_idx] = idx++;
        temp_for_idx = temp_for_idx->next;
    }

    idx = 0;
    while (current_original != NULL) {
        cout << "Node " << idx << " (Val: " << current_original->val << ")";
        if (current_original->random) {
            cout << ", Random points to Node " << original_node_idx[current_original->random];
        } else {
            cout << ", Random points to NULL";
        }
        cout << endl;
        current_original = current_original->next;
        idx++;
    }

    Solution sol;
    Node* copiedListHead = sol.copyRandomList(head);

    cout << "\nCopied List:" << endl;
    Node* current_copied = copiedListHead;
    map<Node*, int> copied_node_idx;
    idx = 0;
    Node* temp_for_idx_copy = copiedListHead;
    while(temp_for_idx_copy != NULL) {
        copied_node_idx[temp_for_idx_copy] = idx++;
        temp_for_idx_copy = temp_for_idx_copy->next;
    }

    idx = 0;
    while (current_copied != NULL) {
        cout << "Node " << idx << " (Val: " << current_copied->val << ")";
        if (current_copied->random) {
            cout << ", Random points to Node " << copied_node_idx[current_copied->random];
        } else {
            cout << ", Random points to NULL";
        }
        cout << endl;
        current_copied = current_copied->next;
        idx++;
    }

    return 0;
}