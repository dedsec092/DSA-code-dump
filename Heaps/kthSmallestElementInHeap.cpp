/*
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
         priority_queue<int> pq;// priority queue is HEAP...
        
        for(int i=0;i<k;i++){
            pq.push(arr[i]);// just push first k elements
        }
        
        for(int i=k;i<=r;i++){
            if(arr[i]<pq.top()){//...update the heap until you have all k number of small eleemnts..
                pq.pop();
                pq.push(arr[i]);//now top element of this heap will be the kth smallest element....
            }
        }
        return pq.top();
    }
};
NOTE: MAX HEAP IS USED TO FIND Kth SMALLEST ELEMENT
.......MIN HEAP WILL BE USED TO FIND "THE Kth LARGEST ELEMENT".....
*/