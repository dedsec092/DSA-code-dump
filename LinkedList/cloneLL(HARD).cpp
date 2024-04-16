/*
USING MAP... O(n) time comlexity && .. O(n) space complexity bcoz of map.....
void insertAtTail(Node* &head,Node* &tail,int d){
    Node* newNode=new Node(d);
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }
    tail->next=newNode;
    tail=newNode;
}
Node *cloneLL(Node *head){
	Node* cloneHead=NULL;
    Node* cloneTail=NULL;
    
    Node* temp=head;
    while(temp!=NULL){
        insertAtTail(cloneHead, cloneTail,  temp->data);
        temp=temp->next;
    }
    unordered_map<Node*,Node*> ogToClone;
    
    Node* originalNode=head;
    Node* cloneNode=cloneHead;
    
    while(originalNode!=NULL){
        ogToClone[originalNode]=cloneNode;
        originalNode=originalNode->next;
        cloneNode=cloneNode->next;
    }
    
     originalNode=head;
     cloneNode=cloneHead;
    while(originalNode!=NULL){
        cloneNode->random=ogToClone[originalNode->random];
        cloneNode=cloneNode->next;
        originalNode=originalNode->next;
    }
    return cloneHead;
}



APPROACH 2:-
TIME COMPLEXITY O(n) && SPACE COMPLEXITY O(1)..

class Solution
{
   private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    

    public:
    Node *copyList(Node *head)
    {
        //step 1: Create a Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        // step 2: insert nodes of Clone List in between originalList
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode  = next;
        }
        
        // step 3: Random pointer copy
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) { 
            
            if(originalNode -> arb != NULL) {
                cloneNode -> arb = originalNode -> arb -> next;
            }
            else
            {
                cloneNode -> arb  = NULL;
            }
            
            cloneNode = cloneNode -> next;
            originalNode = originalNode -> next;
        }
        
        //step 4: revert step 2 changes
        Node* original = head;
        Node* copy = cloneHead;
        
         while (original && copy)
            {
                original->next =
                 original->next? original->next->next : original->next;
         
                copy->next = copy->next?copy->next->next:copy->next;
                original = original->next;
                copy = copy->next;
            }

        // step 5 answer return
        return cloneHead;
    }
};
*/