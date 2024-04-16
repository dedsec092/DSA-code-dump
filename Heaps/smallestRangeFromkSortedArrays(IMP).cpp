/*
#include<queue>
#include<limits.h>
class node{
    public:
    int data;
    int row;
    int col;

    node(int d,int r,int c){
        data=d;
        row=r;
        col=c;
    }
};

class compare{
    public:
    bool operator()(node*a,node*b){
        return a->data>b->data;
    }
}; 
int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini=INT_MAX;//making range
    int maxi=INT_MIN;
    priority_queue<node*,vector<node*>,compare> minHeap;//using minHeap as we need smallest range 

    for(int i=0;i<k;i++){
        int element=a[i][0];
        mini=min(mini,element);
        maxi=max(maxi,element);
        minHeap.push(new node(element,i,0));        
    }

    int start=mini,end=maxi;//intial ranges from 1st colomn..
    //here mini can be increased so that the difference b/w maxi and mini will be small..
    //NOTE if you decrease maxi then the range cannot cover all the arrays
    //INCREASING MINI IS THE ONLY OPTION HERE.. 

    while(!minHeap.empty()){
        node*temp=minHeap.top();
        minHeap.pop();

        mini=temp->data;//updating mini from minHeap top..

        if(maxi-mini<end-start){
            start=mini;//updating answers..
            end=maxi;
        }
        
        if(temp->col+1<n){
            maxi=max(maxi,a[temp->row][temp->col+1]);
            minHeap.push(new node(a[temp->row][temp->col+1],temp->row,temp->col+1));//ADDING NEXT ELEMENT FROM THE SAME ROW..
        }
        else{
            break;//GOTTA TERMINATE HERE EVEN IF MINHEAP IS NOT EMPTY BECAUSE ELEMENT IN TEMP->ROW IS OVER...
        }
    }
    return (end-start)+1;//in thw end you have to make this difference as small as possible..
}
*/