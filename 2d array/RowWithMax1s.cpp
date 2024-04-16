/*
Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).

**********************************************
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int maxCount=0;
	    int rowWithMax=-1;
	    
	    for(int i=0;i<n;i++){
	        int count=0;
	        for(int j=0;j<m;j++){
	            if(arr[i][j]==1){
	                count++;
	            }
	            if(count>maxCount){
	                maxCount=count;
	                 rowWithMax=i;
	            }
	            
	        }
	       
	    }
	    return rowWithMax;
	}
*/