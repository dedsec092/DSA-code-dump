/*
Input: 1->2->3->4->5
Output: 5->1->2->3->4
*************************************
Node *delAddLastNode(Node *head){
    if(head==NULL||head->next==NULL){
        return head;
    }
	Node*curr=head;

    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    int temp=curr->next->data;
    curr->next=NULL;
    Node* NewH=new Node(temp);
    NewH->next=head;
    head=NewH;
    return head;
}
*/