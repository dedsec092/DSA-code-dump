#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node*prev;

    node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
       temp= temp->next;
    }
}

int getLength(node* &head){
    int len=1;
    if(head->next==NULL){
        return 1;
    }
    node*temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}

void insertAtHead(node* &head,int data){
    node* newNode=new node(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}

void insertAtPosition(node* &head,int position,int data){
    if(position==1){
        insertAtHead(head,data);
    }
    node* newNode=new node(data);
    int count=1;
    node* temp=head;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next=newNode;
    
}
void deleteNode(node* &head,int position){
    if(position==1){
        head=head->next;
        head->prev=NULL;
    }
    int count=1;
    node* temp=head;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    temp->next=temp->next->next;

}

int main(){
    node* node1=new node(10);
    node*head=node1;
    insertAtHead(head,8);
    insertAtPosition(head,2,11);
    insertAtPosition(head,3,11);
   deleteNode(head,2);
    deleteNode(head,3);
    print(head);
   // cout<<getLength(head);
}