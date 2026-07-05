#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    //!NAIVE APPROACH
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    //     map <ListNode*,int> mpp;

    //     ListNode* temp1=headA;

    //     while(temp1!=NULL){
    //         mpp[temp1]=1;
    //         temp1=temp1->next;
    //     }

    //     ListNode* temp2=headB;

    //     while(temp2!=NULL){
    //         if(mpp.find(temp2)!=mpp.end()){
    //             return temp2;
    //         }
    //         temp2=temp2->next;
    //     }

    //     return temp2;
    // }

    //!BETTER APPROACH
    // ListNode* collisionPoint(ListNode* temp1,ListNode* temp2, int d){

    //     while(d){
    //         d--;
    //         temp1=temp1->next;
    //     }

    //     while(temp1!=temp2){
    //         temp1=temp1->next;
    //         temp2=temp2->next;
    //     }

    //     return temp1;
    // }

    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){

    //     int n1=0;
    //     int n2=0;

    //     ListNode* temp1=headA;
    //     ListNode* temp2=headB;

    //     while(temp1!=NULL){
    //         n1++;
    //         temp1=temp1->next;
    //     }

    //     while(temp2!=NULL){
    //         n2++;
    //         temp2=temp2->next;
    //     }

    //     if(n1>n2){
    //         return collisionPoint(headA,headB,n1-n2);
    //     }
    //     else{
    //         return collisionPoint(headB,headA,n2-n1);
    //     }
    // } 

    //!OPTIMAL APPROACH
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){

        if(headA==NULL || headB==NULL){
            return NULL;
        }

        ListNode* temp1=headA;
        ListNode* temp2=headB;

        while(temp1!=temp2){

            temp1=temp1->next;
            temp2=temp2->next;

            if(temp1==temp2){
                return temp1;
            }

            if(temp1==NULL){
                temp1=headB;
            }
            
            if(temp2==NULL){
                temp2=headA;
            }
        }

        return temp1;
    }
};

int main() {
    Solution sol;

    // Create the common intersection part: 4 -> 6 -> 2
    ListNode* intersection_node_4 = new ListNode(4);
    ListNode* node_6 = new ListNode(6);
    ListNode* node_2 = new ListNode(2);

    intersection_node_4->next = node_6;
    node_6->next = node_2;

    // Create List A: 3 -> 1 -> (common part)
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(1);
    headA->next->next = intersection_node_4; // Link to the common part

    // Create List B: 1 -> 2 -> 4 -> 5 -> (common part)
    ListNode* headB = new ListNode(1);
    headB->next = new ListNode(2);
    headB->next->next = new ListNode(4); // This '4' is not the intersection node object
    headB->next->next->next = new ListNode(5);
    headB->next->next->next->next = intersection_node_4; // Link to the common part

    cout << "Example with specific intersection:" << endl;
    cout << "List A: 3 -> 1 -> [4 -> 6 -> 2]" << endl;
    cout << "List B: 1 -> 2 -> 4 -> 5 -> [4 -> 6 -> 2]" << endl;
    cout << "Intersection starts at the common node with value 4." << endl;


    ListNode* intersectionResult = sol.getIntersectionNode(headA, headB);

    if (intersectionResult) {
        cout << "Intersection found at node with value: " << intersectionResult->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    // Remember to deallocate memory in a real application
    // (omitted for brevity in this example)

    return 0;
}