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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        map<int, int> inMap;

        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }

        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);
    }

    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int, int>& inMap){

        if(inStart > inEnd || postStart > postEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(inorder, inStart, inRoot-1, postorder, postStart, postStart+numsLeft-1, inMap);
        root->right = buildTree(inorder, inRoot+1, inEnd, postorder, postStart+numsLeft, postEnd-1, inMap);

        return root;
    }
};

int main(){

    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};

    Solution obj;
    TreeNode* root = obj.buildTree(inorder, postorder);

    if(!root) return 0;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout << endl;
    }
}