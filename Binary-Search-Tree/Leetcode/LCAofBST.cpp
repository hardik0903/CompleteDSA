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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        int cur = root->val;
        if(cur>p->val && cur>q->val) return lowestCommonAncestor(root->left, p, q);

        if(cur<p->val && cur<q->val) return lowestCommonAncestor(root->right, p, q);

        return root;
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
    root->right->right = new TreeNode(7);
    TreeNode* p = root->right->right;
    TreeNode* q = root->left->left;

    Solution sol;
    TreeNode* ans = sol.lowestCommonAncestor(root, p, q);
    cout<<"Lowest Common Ancestor of "<<p->val<<" and "<<q->val<<" is: "<<ans->val;

    return 0;
}