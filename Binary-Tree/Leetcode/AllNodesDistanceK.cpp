#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        right=left=nullptr;
    }
};

class BinaryTree{
private:
    void makeParent(Node* root, unordered_map<Node*, Node*> &parent_track, Node* target){

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
public:
    vector<int> distanceK(Node* root, int k, Node* target){

        unordered_map<Node*, Node*> parent_track;
        unordered_map<Node*, bool> visited;
        queue<Node*> queue;
        int dist=0;

        makeParent(root, parent_track, target);

        queue.push(target);
        visited[target]=true;

        while(!queue.empty()){
            int size = queue.size();

            if(dist++ == k) break;

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
        }

        vector<int> result;

        while(!queue.empty()){
            Node* current = queue.front();
            queue.pop();

            result.push_back(current->data);
        }
        return result;
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

    BinaryTree b;

    vector<int> result= b.distanceK(root, 2, root->left);

    for(int i: result){
        cout<<i<<" ";
    }

    return 0;
    
}