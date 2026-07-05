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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode* cur = root;

        while(true){

            if(cur->val <= val){
                if(cur->right != NULL) cur = cur->right;
                else{
                    cur->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(cur->left != NULL) cur = cur->left;
                else{
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};

int main() {
    // 1. Manually construct a valid BST:
    //       4
    //      / \
    //     2   7
    //    / \
    //   1   3
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    cout << "Original Tree created." << endl;

    // 2. Insert value 5
    // Expected logic:
    // 5 > 4 (Go Right -> to node 7)
    // 5 < 7 (Go Left  -> Empty spot found)
    // Result: 5 becomes left child of 7.
    Solution sol;
    cout << "Inserting value 5..." << endl;
    sol.insertIntoBST(root, 5);

    // 3. Verify specific locations
    if(root->right->left != NULL && root->right->left->val == 5) {
        cout << "Success! Found 5 at root->right->left." << endl;
    } else {
        cout << "Error: Node 5 not found in expected location." << endl;
    }

    // 4. Simple print of the right subtree to confirm
    cout << "Right Subtree Check: " << root->right->val << " (Left child: " << root->right->left->val << ")" << endl;

    return 0;
}