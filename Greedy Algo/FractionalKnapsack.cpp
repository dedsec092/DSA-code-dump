/*
QUESTION: Given weights and values of N items, we need to put these items in a
 knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item here. 

Example 1:

Input:
N = 3, W = 50
value[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.000000

APPROACH : SORT ACCORDING TO VALUE PER UNIT 

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(pair<double,Item> a,pair<double,Item> b){// util for sorting according to valuePerUnit
        return a.first> b.first ;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,Item>> v;
        
        for(int i=0;i<n;i++){
            double valuePerUnit=(1.0*arr[i].value)/arr[i].weight;
            pair<double ,Item> p=make_pair(valuePerUnit,arr[i]);
            v.push_back(p);
        }
        sort(v.begin(),v.end(),cmp);// sorting according to valuePerUnit
        
        double totalValue=0;
        for(int i=0;i<n;i++){
            if(v[i].second.weight>W){// taking fractional value of item
                totalValue+=W*v[i].first;
                W=0; // weight used
            }
            else{
                totalValue+=v[i].second.value;
                W=W-v[i].second.weight;
            }
        }
        return totalValue;
        
    }
*/