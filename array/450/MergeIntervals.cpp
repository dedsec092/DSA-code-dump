/*
For the given 5 intervals - [1, 4], [3, 5], [6, 8], [10, 12], [8, 9].

Since intervals [1, 4] and [3, 5] overlap with each other, we will merge them into a single interval as [1, 5].

Similarly, [6, 8] and [8, 9] overlap, merge them into [6,9].

Interval [10, 12] does not overlap with any interval.

Final List after merging overlapping intervals: [1, 5], [6, 9], [10, 12].
***************************************************************************

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)

{

    vector<vector<int>>ans; 
    sort(intervals.begin(),intervals.end());  

    for(int i=0;i<intervals.size();i++){
        if(ans.empty() or intervals[i][0]>ans.back()[1]) { 
            ans.push_back(intervals[i]);// HERE ONLY ONE INDEX IS SPECIFIED IN A 2D ARRAY SO WHOLE ROW WILL BE PUSHED
        }
        else{  
           ans.back()[1]=max(ans.back()[1],intervals[i][1]); // MERGING STEP
        }    
    } 
    return ans;        
}

*/