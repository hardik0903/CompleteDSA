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

vector<int> preOrderTraversal(Node* root){

    vector<int> pot;
    stack<Node*> st;

    if(root==NULL){
        return pot;
    }

    st.push(root);

    while(!st.empty()){
        Node* curr= st.top();
        st.pop();

        pot.push_back(curr->data);

        if(curr->right!=NULL){
            st.push(curr->right);
        }

        if(curr->left!=NULL){
            st.push(curr->left);
        }
    }
    return pot;
}

int main(){

    struct Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(17);

    vector<int> ans= preOrderTraversal(root);

    for(int a: ans){
        cout<<a<<" ";
    }
}

