#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class node{
    public:
        int key;
        int val;
        node* next;
        node* prev; 
        node(int _key, int _val){
            key=_key;
            val=_val;
        }
    };

    map<int,node*> mpp;
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    int cap;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        head->prev=NULL;
        tail->next=NULL;
    }

    void deleteNode(node* cur){
        node* prevNode=cur->prev;
        node* nextNode=cur->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }

    void insertAfterHead(node* cur){
        node* currAfterHead=head->next;
        head->next=cur;
        cur->next=currAfterHead;
        cur->prev=head;
        currAfterHead->prev=cur;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        node* node=mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            node* needed=mpp[key];
            needed->val=value;
            deleteNode(needed);
            insertAfterHead(needed);
        }
        else{
            if(mpp.size()==cap){
                node* notneeded=tail->prev;
                mpp.erase(notneeded->key);
                deleteNode(notneeded);
            }
            node* newnode=new node(key,value);
            mpp[key]=newnode;
            insertAfterHead(newnode);
        }
    }
};

int main() {
    // Create an LRU cache with capacity 4
    LRUCache cache(4);

    // Perform the sequence of operations
    cache.put(2, 6);
    cache.put(4, 7);
    cache.put(8, 11);
    cache.put(7, 10);

    // These should print the returned values of get()
    cout << cache.get(2) << "\n";   // Expected output: 6
    cout << cache.get(8) << "\n";   // Expected output: 11

    cache.put(5, 6);

    cout << cache.get(7) << "\n";   // Expected output: 10

    cache.put(5, 7);

    return 0;
}
