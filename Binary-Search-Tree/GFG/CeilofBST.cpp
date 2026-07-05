#include <iostream>

using namespace std;

// Definition for the BST Node based on your code usage
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int val = -1;
        
        while(root){
            
            if(root->data == x){
                val = root->data;
                return val;
            }
            
            if(x > root->data){
                root = root->right;
            }
            else{
                val = root->data;
                root = root->left;
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

    // Test Case 1: Find Ceil of 5
    // 5 is not in the tree. The next greater element is 6.
    int x1 = 5;
    cout << "Ceil of " << x1 << " is: " << sol.findCeil(root, x1) << " (Expected: 6)" << endl;

    // Test Case 2: Find Ceil of 11
    // 11 is not in the tree. The next greater element is 12.
    int x2 = 11;
    cout << "Ceil of " << x2 << " is: " << sol.findCeil(root, x2) << " (Expected: 12)" << endl;

    // Test Case 3: Find Ceil of 20 (Larger than max node)
    // Should return -1
    int x3 = 20;
    cout << "Ceil of " << x3 << " is: " << sol.findCeil(root, x3) << " (Expected: -1)" << endl;

    return 0;
}