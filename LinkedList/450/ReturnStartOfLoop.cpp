/*
Node* detect(Node*head){// FOR CYCLE DETECTION
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return slow;// MEET OF FAST AND SLOW
        }
    }
    return NULL;
}

Node *firstNode(Node *head)
{
   Node* start=head;
   Node* meet=detect(head);
   if(meet==NULL){
       return NULL;
   }
   while(start!=meet){// START AND MEET WILL BECOME EQUAL AT THE STARTING OF THE LINKED LIST LOOP
       start=start->next;
       meet=meet->next;
   }
   return start;
}
*/