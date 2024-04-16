/*
input:
LinkedList: 2->2->4->5
Output: 2 4 5
***************************************************************
Node *removeDuplicates(Node *head)
{
        if(head==NULL){
            return NULL;
        }
        Node * curr=head;
        while(curr!=NULL){
            if((curr->next!=NULL)&& curr->data==curr->next->data){
                curr->next=curr->next->next;
            }
            else{
                curr=curr->next;
            }
        }
        return head;
}
*/