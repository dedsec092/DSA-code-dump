/*
Node * removeDuplicates(Node *head)
{
    if(head==NULL){
        return head;
    }
    Node* curr=head;
    while(curr!=NULL){
        if((curr->next!=NULL)&&curr->data==curr->next->data){
             curr->next=curr->next->next;
            
        }
        else{
           curr=curr->next;
        }
    }
    return head;
}

*/
