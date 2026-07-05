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

class Solution{
public:
    TreeNode* searchBST(TreeNode* root, int val){

        while(root!=NULL && root->val!=val){
            root = root->val<val?root->right:root->left;
        }
        return root;
    }
};

int main(){
    TreeNode* root = new TreeNode(8);
    TreeNode* leftRoot = new TreeNode(5);
    TreeNode* leftofleft = new TreeNode(4);
    TreeNode* leftofRight = new TreeNode(7);
    TreeNode* rightofleft = new TreeNode(6);
    root->left=leftRoot;
    leftRoot->left=leftofleft;
    leftRoot->right=leftofRight;
    leftofRight->left=rightofleft;

    TreeNode* rightRoot = new TreeNode(12);
    TreeNode* leftofright = new TreeNode(10);
    TreeNode* rightofright = new TreeNode(14);
    TreeNode* leftofright2 = new TreeNode(13);
    root->right = rightRoot;
    rightRoot->left=leftofright;
    rightRoot->right=rightofright;
    rightofright->left=leftofright2;

    Solution sol;
    TreeNode* ans = sol.searchBST(root, 10);

    if(ans==NULL){
        cout<<"Answer Not Found";
    }
    else{
        cout<<"Node found with value: "<<ans->val;
    }
}