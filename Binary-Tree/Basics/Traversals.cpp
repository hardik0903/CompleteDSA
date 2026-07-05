#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node* right;
    struct Node* left;

    Node(int val){
        data=val;
        left=right=nullptr;
    }
};

void inOrder(struct Node* root){

    if(root==NULL){
        return ;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(struct Node* root){

    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct Node* root){

    if(root==NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){

    struct Node* root = new Node(10);
    root->data=10;
    root->left= new Node(5);
    root->right= new Node(15);

    cout<<"Printing InOrder Traversal: ";
    inOrder(root);
    cout<<endl;

    cout<<"Printing PreOrder Traversal: ";
    preOrder(root);
    cout<<endl;

    cout<<"Printing PostOrder Traversal: ";
    postOrder(root);
    cout<<endl;
}