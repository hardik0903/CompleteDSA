#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node **head_ref, int new_data){
    struct Node* new_node=(struct Node*) malloc(sizeof(struct Node));
    new_node->data=new_data;

    new_node->next=(*head_ref);
    *head_ref=new_node;
}

void insertAfter(struct Node **head_ref,int pos, int new_data){

    struct Node* prev_node=*head_ref;
    struct Node*new_node=(struct Node*)malloc(sizeof(struct Node));

    new_node->data=new_data;

    if(pos==0){
        new_node->next=*head_ref;
        *head_ref=new_node;
    }

    for(int i=0;i<pos-1 && prev_node!=NULL;i++){
        prev_node=prev_node->next;
    }

    new_node->next=prev_node->next;
    prev_node->next=new_node;

}

void insertAtEnd(struct Node** head_ref, int new_data){
    struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));

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

void deleteNode(struct Node** head_ref, int key){
    struct Node* temp=*head_ref,*prev;

    if(temp!=NULL && temp->data==key){
        *head_ref=temp->next;
        free(temp);
        return;
    }

    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL){
        return;
    }

    prev->next=temp->next;
    free(temp);
}

bool searchNode(struct Node** head_ref, int key){
    struct Node *temp=*head_ref;

    while(temp!=NULL){

        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }

    return false;
}

void sortLinkedList(struct Node** head_ref){

    struct Node* current=*head_ref,*index;
    int temp;

    if(*head_ref==NULL){
        return;
    }
    else{
        while(current!=NULL){
            index=current->next;

            while(index!=NULL){

                if(current->data>index->data){
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

void printList(struct Node* node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
}

void lengthList(struct Node* node){
    int cnt=0;
    while(node!=NULL){
        cnt+=1;
        node=node->next;
    }
    cout<<"Length of Linked List is: "<<cnt<<endl;
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
            "8. Length of Linked List\n"
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
        int index;
        cout<<"Enter Position data to be inserted at: ";
        cin>>index;
        insertAfter(head_ref,index,data2);
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

    case 8:
        lengthList(*head_ref);

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
