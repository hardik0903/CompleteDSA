#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data=val;
        right=left=nullptr;
    }
};

bool isSumProperty(Node* root){

    if(root==NULL) return true;
    if(root->left==NULL && root->right==NULL) return true;

    int child=0;
    if(root->left) child+=root->left->data;
    if(root->right) child+=root->right->data;

    return ((root->data == child) && (isSumProperty(root->left)) && (isSumProperty(root->right)));
}

int main(){

    struct Node* root = new Node(150);
    root->left = new Node(80);
    root->right = new Node(70);
    root->left->left = new Node(40);
    root->left->right = new Node(40);
    root->right->left = new Node(30);
    root->right->right = new Node(40);

    if(isSumProperty(root)){
        cout<<"It follows Children Sum Property"<<endl;
    }

    else{
        cout<<"It doesn't follows Children Sum Property"<<endl;
    }
}