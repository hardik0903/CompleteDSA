#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL){
            return NULL;
        }

        if(root->val == key){
            return helper(root);
        }

        TreeNode* dummy = root;
        while(root!=NULL){

            if(root->val > key){
                if(root->left !=NULL && root->left->val==key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else{
                if(root->right !=NULL && root->right->val==key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return dummy;
    }

    TreeNode* helper(TreeNode* root){

        if(root->left == NULL){
            return root->right;
        }

        else if(root->right==NULL){
            return root->left;
        }

        TreeNode* rightChild = root->right;
        TreeNode* leftRight = findRightMax(root->left);
        leftRight->right = rightChild;

        return root->left;
    }

    TreeNode* findRightMax(TreeNode* root){

        if(root->right ==NULL){
            return root;
        }

        return findRightMax(root->right);
    }
};

int main() {
    // 1. Manually construct a BST:
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

    // 2. Instantiate and Delete Node 3
    Solution sol;
    cout << "Deleting node 3..." << endl;
    root = sol.deleteNode(root, 3);

    // 3. Verify specific changes manually
    if (root->left != NULL) {
        cout << "Root->left is now: " << root->left->val << " (Expected: 2)" << endl;
        
        if (root->left->right != NULL) {
            cout << "Root->left->right is now: " << root->left->right->val << " (Expected: 4)" << endl;
        } else {
            cout << "Error: Right child of 2 is missing!" << endl;
        }
    }

    return 0;
}