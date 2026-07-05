#include <bits/stdc++.h>

using namespace std;

//Create a Node
struct Node{
    int data;
    struct Node* next;
};

//Insert at Beginning
void insertAtBeginning(struct Node** head_ref, int new_data){
    
    //Allocate Memory
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));

    //Insert Data
    new_node->data=new_data;
    new_node->next=(*head_ref);

    //Move head
    (*head_ref)=new_node;
}

//Insert At Between
void insertAfter(struct Node* prev_node, int new_data){

    if(prev_node==NULL){
        cout<<"The given previous node cannot be NULL";
        return;
    }

    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));

    new_node->data=new_data;
    new_node->next=prev_node->next;
    prev_node->next=new_node;
}

//Insert At End
void insertAtEnd(struct Node** head_ref, int new_data){
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));

    struct Node* last=*head_ref;

    new_node->data=new_data;
    new_node->next=NULL;

    if(*head_ref==NULL){
        *head_ref=new_node;
        return;
    }

    while(last->next!=NULL){
        last=last->next;
    }
    last->next=new_node;
}

//Delete a Node
void deleteNode(struct Node**head_ref, int key){
    struct Node* temp= *head_ref, *prev;

    if(temp!=NULL && temp->data==key){
        *head_ref=temp->next;
        free(temp);
        return;
    }

    //Find the key to be deleted
    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL){
        return;
    }

    //Remove the Node
    prev->next=temp->next;
    free(temp);
}

//Search a Node
bool searchNode(struct Node** head_ref, int key){
    struct Node* current = *head_ref;

    while(current!=NULL){
        if(current->data==key){
            return true;
        }
        current=current->next;
    }
    return false;
}

//Sort the Linked List
void sortLinkedList(struct Node** head_ref){
    struct Node *current = *head_ref, *index;
    int temp;

    if(head_ref==NULL){
        return;
    }
    else{
        while(current!=NULL){
            //Index points to the node next to current
            index=current->next;

            while(index!=NULL){
                if(index->data<current->data){
                    temp=current->data;
                    current->data=index->data;
                    index->data=temp;
                }
                index=index->next;
            }
            current=current->next;
        }
    }
}

//Print the Linked List
void printList(struct Node *node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
}

void menuOfLinkedList(struct Node** head_ref){

    int n;
    cout<<"Here is the Menu of Linked List Functions: \n"
            "1. Insert at Beginning\n"
            "2. Insert at Between\n"
            "3. Insert at End\n"
            "4. Delete a Node\n"
            "5. Search a Node\n"
            "6. Sort the Linked List\n"
            "7. Print the Linked List\n"
            "Provide your Input:- ";
    cin>>n;

    switch (n)
    {
    case 1:
        int data1;
        cout<<"Enter Data: ";
        cin>>data1;
        insertAtBeginning(head_ref,data1);
        cout<<"DATA INSERTED AT BEGINNING"<<endl;
        break;

    case 2:
        int data2;
        cout<<"Enter Data: ";
        cin>>data2;
        insertAfter(*head_ref,data2);
        cout<<"DATA INSERTED AT BETWEEN"<<endl;
        break;

    case 3:
        int data3;
        cout<<"Enter Data: ";
        cin>>data3;
        insertAtEnd(head_ref,data3);
        cout<<"DATA INSERTED AT END"<<endl;
        break;

    case 4:
        int key1;
        cout<<"Enter key to be Deleted: ";
        cin>>key1;
        deleteNode(head_ref,key1);
        cout<<"DATA DELETED"<<endl;
        break;

    case 5:
        int key2;
        cout<<"Enter key to be Searched: ";
        cin>>key2;
        if (searchNode(head_ref,key2)){
            cout<<"FOUND THE KEY"<<endl;
        }
        else{
            cout<<"NOT FOUND THE KEY"<<endl;
        }
        
        break;
    
    case 6:
        sortLinkedList(head_ref);
        cout<<"LINKED LIST SORTED"<<endl;
        break;

    case 7:
        cout<<"Linked List: ";
        printList(*head_ref);
        cout<<"LINKED LIST PRINTED"<<endl;
        break;

    default:
        break;
    }

}

int main(){

    struct Node *head=NULL;

    while(1){
        menuOfLinkedList(&head);
    }

    return 0;

}
