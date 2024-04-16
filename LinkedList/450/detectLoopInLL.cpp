/*
bool detectCycle(Node *head){
		Node* turtle=head;
		Node*Hare=head->next;
		while(Hare!=NULL&& Hare->next!=NULL ){
			Hare=Hare->next->next;
			turtle=turtle->next;
			if(Hare==turtle){
				return true;
			}
		}
		return false;
}
*/