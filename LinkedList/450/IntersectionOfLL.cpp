/*
Example:-
L1 = 1->2->3->4->7
L2 = 2->4->6->7

ANSWER:- The answer should be 2->4->7 because 2,4, and 7 are present in both the linked lists.
**************************************************************
Node* intersect_ll(Node* L1, Node *L2){

    Node* ptr=new Node(-1);
    Node* ans=ptr;

    while(L1 && L2){
        if(L1->data==L2->data){
            ptr->next=new Node(L1->data);
            ptr=ptr->next;
            L1=L1->next;
            L2=L2->next;
        }
        else{
            L1=L1->next;
        }
    }
    return ans->next;
}
*/