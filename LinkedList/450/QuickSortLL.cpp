/*
n = 4
list = {1,9,3,8}
Output:
1 3 8 9

***********************************************************************
node* findTail(struct node *head){
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp;
}

node* partition(node* head,node* tail){
    node* pivot=head;
    node*prev=head;
    node*curr=head->next;
    while(curr!=tail->next){
        if(curr->data<pivot->data){
            swap(prev->next->data,curr->data);
            prev=prev->next;
        }
        curr=curr->next;
    }
    swap(prev->data,pivot->data);
    return prev;
}

void solveSort(node* head,node* tail){
    if(head==NULL || tail==NULL || head==tail){
        return ;
    }
    node* pivot=partition(head,tail);// PIVOT WILL BE ON RIGHT POSITION 
    solveSort(head,pivot); // QUICK SORT ON FIRST HALF
    solveSort(pivot->next,tail); // QUICK SORT ON OTHER HALF RECURSIVLY
}

void quickSort(struct node **headRef) {
    node* head=*headRef;
    if(head==NULL || head->next==NULL){
        return ;
    }
    node* tail=findTail(head);
    solveSort(head,tail);
    
}
*/