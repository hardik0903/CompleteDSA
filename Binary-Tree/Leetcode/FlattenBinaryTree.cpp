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
private:
    TreeNode* prev=NULL;
public:

    //!APPROACH 1: RECURSIVE APPROACH
    // void flatten(TreeNode* root) {
        
    //     if(root==NULL){
    //         return;
    //     }

    //     flatten(root->right);
    //     flatten(root->left);

    //     root->right=prev;
    //     root->left=NULL;
    //     prev=root;
    // }

    //!APPROACH 2: ITERATIVE APPROACH
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        if(root==NULL) return;
        st.push(root);

        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();

            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);

            if(!st.empty()) cur->right=st.top();
            cur->left=NULL;
        }
    }
};

int main() {
    // 1. Manually construct the tree:
    //       1
    //      / \
    //     2   5
    //    / \   \
    //   3   4   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // 2. Instantiate and run
    Solution sol;
    sol.flatten(root);

    // 3. Print the result
    // Since the tree is flattened, we just traverse the 'right' pointer.
    cout << "Flattened List: ";
    
    TreeNode* curr = root;
    while(curr != NULL) {
        cout << curr->val;
        
        // Sanity check: Left child should always be NULL after flattening
        if(curr->left != NULL) {
            cout << " (Error: Found left child!) ";
        }

        if(curr->right != NULL) cout << " -> ";
        curr = curr->right;
    }
    cout << endl;

    return 0;
}