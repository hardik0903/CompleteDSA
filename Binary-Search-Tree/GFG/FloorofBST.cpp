#include <iostream>

using namespace std;

// Definition for the BST Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int floor(Node* root, int x) {
        // code here
        int val=-1;
        
        while(root){
            
            if(root->data == x){
                val = root->data;
                return val;
            }
            
            if(x < root->data){
                root = root->left;
            }
            else{
                val = root->data;
                root = root->right;
            }
        }
        
        return val;
    }
};

int main() {
    // 1. Construct a Binary Search Tree (BST) manually
    //        8
    //       / \
    //      4   12
    //     / \  / \
    //    2   6 10 14
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    Solution sol;

    // Test Case 1: Find Floor of 7
    // 7 is not in tree. Nodes smaller than 7 are 6, 4, 2...
    // The largest of these is 6.
    int x1 = 7;
    cout << "Floor of " << x1 << " is: " << sol.floor(root, x1) << " (Expected: 6)" << endl;

    // Test Case 2: Find Floor of 1 (Smaller than any node)
    // Should return -1 (default value)
    int x2 = 1;
    cout << "Floor of " << x2 << " is: " << sol.floor(root, x2) << " (Expected: -1)" << endl;

    // Test Case 3: Find Floor of 10 (Exact match)
    // Should return 10
    int x3 = 10;
    cout << "Floor of " << x3 << " is: " << sol.floor(root, x3) << " (Expected: 10)" << endl;

    return 0;
}