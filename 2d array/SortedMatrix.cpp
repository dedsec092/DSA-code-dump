/*
Input:
N=4
Mat=[[10,20,30,40],
[15,25,35,45] 
[27,29,37,48] 
[32,33,39,50]]

Output:
10 15 20 25 
27 29 30 32
33 35 37 39
40 45 48 50


***********************************************
 vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector<vector<int>> ans;
        vector<int> arr;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                arr.push_back(Mat[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        
        int index=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                ans[i][j]=arr[index++];
            }
        }
        return ans;
    }
*/