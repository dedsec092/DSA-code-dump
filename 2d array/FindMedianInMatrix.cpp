/*
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives 
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 

*************************************************************
int median(vector<vector<int>> &matrix, int R, int C){
        vector<int> arr;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            arr.push_back(matrix[i][j]);
        }
    }
 
    // Sort the array
    sort(arr.begin(), arr.end());
 
    // Find the median element
    int mid = arr.size() / 2;
    int median;
    if (arr.size() % 2 == 0) {
        median = (arr[mid-1] + arr[mid]) / 2;
    } else {
        median = arr[mid];
    }
 
    return median;
    }


    TIME COMPLEXITY: O(R*C)
    SPACE COMPLEXITY: O(R+C)\
    
    CAN BE OPTIMISED!!!!!
*/