/*
Node* kReverse(Node* head, int k) {
    if(head==NULL){
        return NULL;
    }
  
    int count=0;
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    while(curr!=NULL&&count<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    if(forward!=NULL){
        head->next=kReverse(forward,k);
    }
    return prev;
}

EX-: 1 2 3 4 5 6 7 8 ,,,k=3
output-:3 2 1 6 5 4 8 7 

if output required-:3 2 1 6 5 4 7 8 ..."7 8" is not reversed ... 
APPROACH:-

int getLength(Node* head){
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
Node* kReverse(Node* head, int k) {
    int len=getLength(head);
    if(head==NULL||k>len){
        return head;
    }
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    int count=0;
    while(curr!=NULL&&count<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    if(forward!=NULL){
        head->next=kReverse(forward,k);
    }
    return prev;
}

*/