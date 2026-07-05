#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        right=left=nullptr;
    }
};

vector<int> inorderTraversal(Node* root){

    Node* cur=root;
    vector<int> inorder;

    while(cur!=NULL){

        if(cur->left==NULL){
            inorder.push_back(cur->data);
            cur=cur->right;
        }

        else{
            Node* prev=cur->left;

            while(prev->right && prev->right!=cur){
                prev=prev->right;
            }

            if(prev->right==NULL){
                prev->right=cur;
                cur=cur->left;
            }
            else{
                prev->right=NULL;
                inorder.push_back(cur->data);
                cur=cur->right;
            }
        }
    }
    return inorder;
}

int main(){

    struct Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(17);

    vector<int> ans= inorderTraversal(root);

    for(int a: ans){
        cout<<a<<" ";
    }
}