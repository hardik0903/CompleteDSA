#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val=data;
        right=left=nullptr;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode* root, long minVal, long maxVal){
        if(root==NULL) return true;

        if(root->val >= maxVal || root->val <= minVal) return false;

        return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
    }
};

int main() {
    // Manually construct a BST:
    //       5
    //      / \
    //     3   6
    //    / \   \
    //   2   4   7
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(7);

    Solution sol;
    
    if(!sol.isValidBST(root)){
        cout<<"Program correctly finds out about Falsified BST"<<endl;
    }
    else{
        cout<<"Program incorrectly finds out about BST"<<endl;
    }
}