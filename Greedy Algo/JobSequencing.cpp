/*
QUESTION:Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time.
 We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.
Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
********************************************************************

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a,Job b){// SORTING ACCORDING TO PROFIT
        return a.profit>b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);// SORTING ACCORDING TO PROFIT
        int maxDeadEnd=INT_MIN;
        
        for(int i=0;i<n;i++){
            maxDeadEnd=max(maxDeadEnd,arr[i].dead);
        }
        
        vector<int> schedule(maxDeadEnd+1,-1) ;//+1 because 1 based indexing
        
        int maxProfit=0;
        int count=0;
        
        for(int i=0;i<n;i++){
            int currProfit=arr[i].profit;
            int currDead=arr[i].dead;
            int currId=arr[i].id;
            
            for(int k=currDead;k>0;k--){// FILLING SCHEDULE (IF DEADLINE IS 2 THEN NEED TO FILL BOTH 1 AND 2)
                if(schedule[k]==-1){// IF SCHEDULE IS EMPTY 
                    maxProfit+=currProfit;
                    count++;
                    schedule[k]=currId;// FILLING SCHEDULE (IF DEADLINE IS 2 THEN NEED TO FILL BOTH 1 AND 2)
                    break ;// CATCH(IF WE DONT BREAK HERE THEN currProfit MIGHT GET ADDED 2 OR MORE TIMES )
                }
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(maxProfit);
        return ans;
    } 
*/