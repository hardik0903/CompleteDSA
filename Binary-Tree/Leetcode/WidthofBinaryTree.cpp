#include <bits/stdc++.h>
using namespace std;

struct Node{

    Node* left;
    Node* right;
    int data;

    Node(int val){
        data=val;
        right=left=nullptr;
    }
};

int widthofBinaryTree(Node* root){

    int ans=0;
    queue<pair<Node*, int>> q;
    q.push({root,0});

    while(!q.empty()){

        int min=q.front().second;
        int first, last;
        int size=q.size();

        for(int i=0;i<size;i++){

            int cur_id = q.front().second - min;
            Node* node = q.front().first;
            q.pop();

            if(i==0) first = cur_id;
            if(i==size-1) last= cur_id;

            if(node->left){
                q.push({node->left, 2*cur_id+1});
            }

            if(node->right){
                q.push({node->right, 2*cur_id+2});
            }
        }

        ans =max(ans, last-first+1);
    }
    return ans;
}

int main(){

    struct Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(17);

    int ans = widthofBinaryTree(root);

    cout<<"Width of the given binary tree is: "<<ans<<endl;

}