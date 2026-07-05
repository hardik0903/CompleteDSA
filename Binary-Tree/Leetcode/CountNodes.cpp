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
private:
    int computeLeftHeight(TreeNode* root, int &cnt){
        if(root==NULL) return 0;

        if(root->left){
            cnt++;
            computeLeftHeight(root->left, cnt);
        }
        return cnt;
    }

    int computeRightHeight(TreeNode* root, int &cnt){
        if(root==NULL) return 0;

        if(root->right){
            cnt++;
            computeRightHeight(root->right, cnt);
        }
        return cnt;
    }

public:
    int countNodes(TreeNode* root){
        if(root==NULL) return 0;
        int cnt=1;

        int lh=computeLeftHeight(root, cnt);
        cnt=1;
        int rh=computeRightHeight(root, cnt);

        if(lh==rh){
            return (1<<lh)-1;
        }

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};


int main(){
    struct TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(4);

    Solution b;

    int result= b.countNodes(root);

    cout<<"Number of Nodes are: "<<result;
}