#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  private:
    void makeParents(Node* root, unordered_map<Node*, Node*> &parent_track, Node* target){
        queue<Node*> queue;
        queue.push(root);
        
        while(!queue.empty()){
            Node* current=queue.front();
            queue.pop();
            
            if(current->left){
                queue.push(current->left);
                parent_track[current->left]=current;
            }
            
            if(current->right){
                queue.push(current->right);
                parent_track[current->right]=current;
            }
        }
    }
    
    Node* traversaltofindTarget(Node* root, int target){
        queue<Node*> queue;
        
        if(root==NULL) return nullptr;
        queue.push(root);
        
        while(!queue.empty()){
            int size=queue.size();
            
            for(int i=0;i<size;i++){
                Node* current = queue.front();
                queue.pop();
            
                if(current->data == target) return current;
            
                if(current->left){
                    queue.push(current->left);
                }
            
                if(current->right){
                    queue.push(current->right);
                }
            }
        }
        return nullptr;
    }

  public:
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*, Node*> parent_track;
        Node* targett=traversaltofindTarget(root, target);
        int time=0;
        
        makeParents(root, parent_track, targett);
        
        unordered_map<Node*, bool> visited;
        queue<Node*> queue;
        
        queue.push(targett);
        visited[targett]=true;
        
        while(!queue.empty()){
            int size=queue.size();
            
            for(int i=0;i<size;i++){
                Node* current = queue.front();
                queue.pop();
                
                if(current->left && !visited[current->left]){
                    queue.push(current->left);
                    visited[current->left]=true;
                }
                
                if(current->right && !visited[current->right]){
                    queue.push(current->right);
                    visited[current->right]=true;
                }
                
                if(parent_track[current] && !visited[parent_track[current]]){
                    queue.push(parent_track[current]);
                    visited[parent_track[current]]=true;
                }
            }
            time++;
        }
        return time-1;
    }
};

int main(){

    struct Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Solution b;

    int result= b.minTime(root, 5);

    cout<<"Time Taken: "<<result;

    return 0;
    
}