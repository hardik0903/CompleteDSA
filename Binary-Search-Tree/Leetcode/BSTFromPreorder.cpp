#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {};
};

class Solution
{
private:
    TreeNode *build(vector<int> &preorder, int &i, int bound)
    {
        if (i == preorder.size() || preorder[i] > bound)
            return NULL;
        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);

        return root;
    }

public:
    TreeNode *bstfromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return build(preorder, i, INT_MAX);
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

int
main()
{
    Tree tree;
    TreeNode *root = tree.buildTree();
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Solution sol;
    TreeNode *ans = sol.bstfromPreorder(preorder);
    tree.displayTree(ans);
}
