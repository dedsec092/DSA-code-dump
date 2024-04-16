/*
    Node* findMiddle(Node* head){
        Node* fast=head->next;
        Node* slow=head;
        
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
*/
