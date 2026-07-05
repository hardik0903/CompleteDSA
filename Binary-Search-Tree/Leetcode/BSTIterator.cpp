#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {};
};

class BSTIterator {
    stack<TreeNode*> myStack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }

private:
    void pushAll(TreeNode* node){
        for(;node!=NULL;myStack.push(node), node=node->left);
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
    TreeNode* root=tree.buildTree();

    BSTIterator* bst=new BSTIterator(root);
    int next = bst->next();
    cout<<"Next Value is: "<<next<<endl;

    bool hasNext = bst->hasNext();
    cout<<"Does it has next: ";
    if(hasNext){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}