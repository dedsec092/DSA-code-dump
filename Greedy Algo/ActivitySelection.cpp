/*
Given N activities with their start and finish day given in array start[ ] and end[ ]. 
Select the maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.

Input:
N = 4
start[] = {1, 3, 2, 5}
end[] = {2, 4, 3, 6}
Output: 
3
*****************************************************
 static bool cmp(pair<int,int> a,pair<int,int> b){// TO SORT ACCORDING TO THE ENDING OF ACTIVITY SO THAT MAX NUMBER OF ACTIVITIES CAN BE ATTAINED
        return a.second<b.second;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int ,int>> v;
        for(int i=0;i<n;i++){
            pair<int,int> p=make_pair(start[i],end[i]);
            v.push_back(p);
        }
        
        sort(v.begin(),v.end(),cmp);// SORTING ACCORDING TO END OF ACTIVITY
        
        int count=1; // FIRST MEETING IS CONFIRM ..HAVE TO CHECK FOR REST OF THE ELEMENTS
        int ansEnd=v[0].second;
        
        for(int i=1;i<n;i++){
            if(ansEnd<v[i].first){
                count++;
                ansEnd=v[i].second;
            }
        }
        return count;
    }
*/