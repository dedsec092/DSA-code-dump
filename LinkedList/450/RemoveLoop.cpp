/*
Node* detect(Node*head){
         Node*fast=head;
        Node*slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return fast;
            }
       }
       return NULL;
    }
    void removeLoop(Node* head)
    {
        //HERE START AND MEET(INTERSECTION OF SLOW AND FAST) WILL MEETUP AT THE STARTING THE LOOP
      Node* start=head;
      Node*meet=detect(head);
      while(meet->next!=start->next){// DRY RUN!!!!
          start=start->next;
          meet=meet->next;
      }
      meet->next=NULL;
       
    }
*/