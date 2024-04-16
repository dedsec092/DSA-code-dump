/*
TOP DOWN APPROACH:
TIME COMPLEXITY :O(N) (IDEALLY)..BUT AS ONE YEAR HAS ONLY 365 DAYS(TRIP PLANED WITHIN A YEAR) WHICH IS A CONSTANT 
                           ... SO TECHNICALLY TIME COMPLEXITY WILL BE O(1)*****

SPACE COMPLEXITY :O(N) 
int solve(int n, vector<int> &days, vector<int> &cost, vector<int> &dp,int index){
    //base case
    if(index>=n){
        return 0;//no cost if ninja reached his location
    }
    if(dp[index]!=-1){
        return dp[index];
    }

    //1 day pass
    int option1=cost[0]+solve(n,  days,  cost, dp,index+1);

    int i;
    //7 days pass
    for(i=index;i<n&&days[i]<days[index]+7;i++);
    int option2=cost[1]+solve(n,  days,  cost, dp, i);

    //30 days pass
    for(i=index;i<n&&days[i]<days[index]+30;i++);

     int option3=cost[2]+solve(n,  days,  cost, dp, i);

     dp[index]=min(option1,min(option2,option3));// calculating minimum cost..
     return dp[index];
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n+1,-1);
    return solve(n,days,cost,dp,0);
}

**************************************************************************************************

BOTTOM UP APPROACH:

int solveTab(int n, vector<int> &days, vector<int> &cost){
     vector<int> dp(n+1,INT_MAX);
     dp[n]=0;

    WHY REVERSE LOOP ?:= AS WE ALREADY USED DP[N] IN BASE CASE WE HAVETO PLACE THE FINAL ANS IN DP[0].....
     for(int k=n-1;k>=0;k--){
        // 1 day pass
         int option1=cost[0]+dp[k+1];

    int i;
    //7 days pass
    for(i=k;i<n&&days[i]<days[k]+7;i++);
    int option2=cost[1]+dp[i];

    //30 days pass
    for(i=k;i<n&&days[i]<days[k]+30;i++);

     int option3=cost[2]+dp[i];

     dp[k]=min(option1,min(option2,option3));
     }
     return dp[0];

}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
   
    return solveTab(n,days,cost);
}
****************************************************************************************************************

SPACE OPTIMIZATION BY USING QUEUES...

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    //HERE THESE QUEUE WILL HAVE CONSTANT SPACE (monthly30 and weekly7)
    //THATS WHY SPACE COMPLEXITY:O(1).............. 

    queue<pair<int,int>> monthly;
    queue<pair<int,int>> weekly;

    int ans=0;
    for(int day:days){
        while(!monthly.empty()&&monthly.front().first+30<=day){//removing expired days from queue
            monthly.pop();
        }
        while(!weekly.empty()&&weekly.front().first+7<=day){
            weekly.pop();
        }
        //ADDING COST FOR CURRENT DAY
        monthly.push(make_pair(day,ans+cost[2]));
        weekly.push(make_pair(day,ans+cost[1]));

        //UPDATING ANS
        ans=min(ans+cost[0],min(monthly.front().second,weekly.front().second));
    }
    return ans;
}
*/