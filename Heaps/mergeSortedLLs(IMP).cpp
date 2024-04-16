/*
SIMILAR TO mergekSortedArrays question...
#include<queue>
class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
};
Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<Node*,vector<Node*>, compare> minHeap;
    int k=listArray.size();

    for(int i=0;i<k;i++){
            minHeap.push(listArray[i]);
          
    }

    Node*head=NULL;// making ans..
    Node*tail=NULL;
    
    while(!minHeap.empty()){
        Node*temp=minHeap.top();
        minHeap.pop();

        if(temp->next!=NULL){
            minHeap.push(temp->next);
        }
        if(head==NULL){
            head=tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    return head;
}
  
*/