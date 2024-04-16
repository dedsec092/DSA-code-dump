/*
N = 4
value[] = {5,2,2,4}
Output: 5 2 4
************************************************
 Node * removeDuplicates( Node *head) 
    {
        unordered_set<int> s;// SET IS LIKE A BAG
        Node*curr=head;
        Node*prev=NULL;
        
        while(curr!=NULL){
            if(s.find(curr->data)!=s.end()){// THIS STATEMENT MEANS DUPLICATE FOUND
                prev->next=curr->next;
                curr=prev->next;
            }
            else{
                s.insert(curr->data);
                prev=curr;
                curr=prev->next;
            }
        }
        return head;
    }
*/