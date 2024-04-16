/*
class Solution{
    public:
    void heapify( vector<int> &c,int i,int size){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<size&&c[left]>c[largest]){
            largest=left;
        }
        if(right<size&&c[right]>c[largest]){
            largest =right;
        }
        
        if(largest!=i){
            swap(c[i],c[largest]);
            heapify(c,largest,size);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> c;// make a vector and push all the elements from a and b... 
        for(int i=0;i<n;i++){
            c.push_back(a[i]);
        }
        for(int i=0;i<m;i++){
            c.push_back(b[i]);
        }
        int i=0;
        int size=c.size();
        //heapify the vector.....
        for(int i=size/2-1;i>=0;i--){
             heapify(c,i,size);
        }
       
        
        return c;
    }
};
*/