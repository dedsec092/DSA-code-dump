/*
LinkedListNode<int> * middle(LinkedListNode<int> *head){
    LinkedListNode<int> *fast=head->next;
    LinkedListNode<int> *slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

LinkedListNode<int> * reversLL(LinkedListNode<int> *head){
   LinkedListNode<int> * curr=head;
   LinkedListNode<int> *prev=NULL;
   LinkedListNode<int> *forward=NULL;

   while(curr!=NULL){
       forward=curr->next;
       curr->next=prev;
       prev=curr;
       curr=forward;
   }
   return prev;

}
bool isPalindrome(LinkedListNode<int> *head) {
    if(head->next==NULL){
        return true;
    }
    LinkedListNode<int> *mid=middle(head);
    LinkedListNode<int> * temp=mid->next;
    mid->next=reversLL(temp);

    LinkedListNode<int> *head1=head;
    LinkedListNode<int> *head2=mid->next;
    while(head2!=NULL){
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    temp=mid->next;
    mid->next=reversLL(temp);
    return true;
}
*/