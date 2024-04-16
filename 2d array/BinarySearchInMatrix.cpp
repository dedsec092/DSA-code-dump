/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        int s=0;
        int e=(row*col)-1;
        int mid=s+(e-s)/2;

        while(s<=e){
            int element=matrix[mid/col][mid%col];... Here col means size of the colomn..
            if(element==target){
                return true;
            }
            else if(element>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return false;
    }
};TIME COMPLEXITY -O(log mn)

    1 4 6 
    9 18 21
    32 40 45...MATRIX EXAMPLE 

  =============================================================================================

    for returning index in pair<int ,int>...

    #include <bits/stdc++.h> 
pair<int, int> search(vector<vector<int>> matrix, int x)
{
    int row=matrix.size();
    int col=matrix[0].size();
    pair<int,int> ans;
    ans.first=-1;
    ans.second=-1;

    int s=0;
    int e=(row*col)-1;

    int mid=s+(e-s)/2;

    while(s<=e){
        int element=matrix[mid/col][mid%col];

        if(element==x){
            ans.first=mid/col;
            ans.second=mid%col;
            return ans;
        }

        else if(element<x){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

*/