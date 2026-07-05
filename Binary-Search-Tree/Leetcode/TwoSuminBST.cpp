#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {};
};

class BSTIterator
{

public:
    stack<TreeNode *> myStack;
    bool reverse=true;

    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if (reverse)
        {
            pushAll(tmpNode->right);
        }
        else
        {
            pushAll(tmpNode->left);
        }
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node)
    {
        for (; node != NULL;)
        {
            myStack.push(node);
            if (reverse)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }
};

class Solution
{
public:
    bool twoSuminBST(TreeNode* root, int k){
        if(!root) return false;

        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i=l.next();
        int j=r.next();

        while(i<j){

            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};

class Tree
{
public:
    TreeNode *buildTree()
    {
        int val;
        cout << "Enter root node value (-1 for NULL): ";
        cin >> val;

        if (val == -1)
            return NULL;

        TreeNode *root = new TreeNode(val);
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            // Input for Left Child
            cout << "Enter " << curr->val << "'s left child value (-1 for NULL): ";
            cin >> val;
            if (val != -1)
            {
                curr->left = new TreeNode(val);
                q.push(curr->left);
            }

            // Input for Right Child
            cout << "Enter " << curr->val << "'s right child value (-1 for NULL): ";
            cin >> val;
            if (val != -1)
            {
                curr->right = new TreeNode(val);
                q.push(curr->right);
            }
        }
        return root;
    }

    void displayTree(TreeNode *root)
    {
        if (!root)
        {
            cout << "Tree is empty." << endl;
            return;
        }

        queue<TreeNode *> q;
        q.push(root);

        cout << "Tree Structure: ";

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            // Only print if there is at least one child to show relationship
            if (curr->left || curr->right)
            {
                cout << curr->val << "->[";

                // Handle Left
                if (curr->left)
                {
                    cout << curr->left->val;
                    q.push(curr->left);
                }
                else
                {
                    cout << "NULL";
                }

                cout << ", ";

                // Handle Right
                if (curr->right)
                {
                    cout << curr->right->val;
                    q.push(curr->right);
                }
                else
                {
                    cout << "NULL";
                }

                cout << "], ";
            }
        }
        cout << endl;
    }
};

int main(){
    Tree tree;
    Solution sol;
    TreeNode* root=tree.buildTree();
    int k;
    cout<<"Enter 2 sum value you need:";
    cin>>k;
    cout<<endl;
    bool ans=sol.twoSuminBST(root, k);
    if(ans){
        cout<<"Two sum Found"<<endl;
    }
    else{
        cout<<"Two sum not available"<<endl;
    }
    return 0;
}
