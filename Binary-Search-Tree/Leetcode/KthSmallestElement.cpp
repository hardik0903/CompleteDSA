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
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int ans=-1;

        while(root!=NULL){

            if(root->left==NULL){
                if(++cnt == k) {
                    ans = root->val;
                }
                root = root->right;
            }
            else{
                TreeNode* prev = root->left;

                while(prev->right && prev->right!=root){
                    prev = prev->right;
                }

                if(prev->right == NULL){
                    prev->right=root;
                    root=root->left;
                }
                else{
                    prev->right=NULL;
                    if(++cnt == k) {
                        ans = root->val;
                    }
                    root = root->right;
                }
            }
        }
        return ans;
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

    Solution sol;
    int k;
    cout<<"Enter k value: ";
    cin>>k;
    int ans = sol.kthSmallest(root, k);

    cout<<"For kth Smallest element ("<<k<<") that is: "<<ans;

    return 0;
}