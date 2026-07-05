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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";

        string str="";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();

            if(currNode==NULL){
                str.append("#,");
            }
            else{
                str.append(to_string(currNode->val)+',');
            }
            if(currNode!=NULL){
                q.push(currNode->left);
                q.push(currNode->right);
            } 
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);

        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();

            getline(s, str, ',');

            if(str=="#"){
                currNode->left=NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                currNode->left=leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');

            if(str=="#"){
                currNode->right=NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                currNode->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

int main() {
    // 1. Manually construct a simple tree: 
    //      1
    //     / \
    //    2   3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    // Add children to 3 to verify deeper structure
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // 2. Instantiate Codec
    Codec ser, deser;

    // 3. Serialize
    string encoded = ser.serialize(root);
    cout << "Serialized String: " << encoded << endl;

    // 4. Deserialize
    TreeNode* ans = deser.deserialize(encoded);

    // 5. Verify results manually (Output should match created tree)
    if (ans != NULL) {
        cout << "Root: " << ans->val << " (Expected: 1)" << endl;
        cout << "Left: " << ans->left->val << " (Expected: 2)" << endl;
        cout << "Right: " << ans->right->val << " (Expected: 3)" << endl;
        cout << "Right->Left: " << ans->right->left->val << " (Expected: 4)" << endl;
        cout << "Right->Right: " << ans->right->right->val << " (Expected: 5)" << endl;
    } else {
        cout << "Tree is null!" << endl;
    }

    return 0;
}