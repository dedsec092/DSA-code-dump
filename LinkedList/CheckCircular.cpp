/*
bool circularLL(Node* head)
{
    if(head==NULL){
		return true;
	}
	
	Node* temp=head->next;
	while(temp!=NULL&&temp!=head){
		temp=temp->next;
	}
	if(temp==head){
		return true;
	}
	
			return false;
	

}
*/