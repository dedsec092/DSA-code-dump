#include<iostream>
using namespace std;

class node{

    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }
   
};

 void insertAtHead(node* &head,int data){
        node* temp=new node(data);
        temp->next=head;
        head=temp;
    }

void insertAtTail(node* &head,int data){
    node*temp=head;
    node* newNode= new node(data);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=NULL;
}

void insertAtPosition(node* &head,int position ,int data){
   node*newNode= new node(data);
    if(position==1){
        insertAtHead(head,data);
        return;
    }
    int count=1;
    node*temp=head;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

void deleteNode(node* &head,int position){
    node*temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    temp->next=temp->next->next;
}

    int main(){
        node* node1=new node(5);
        node* head=node1;
        insertAtHead(head,6);
        insertAtTail(head,7);
        insertAtPosition(head,2,8);
        insertAtPosition(head,1,9);
        insertAtPosition(head,4,4);
        deleteNode(head,4);
         deleteNode(head,4);
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
    }
