/*
nput:
N = 4
K = 2
candies[] = {3 2 1 4}

Output:
3 7

Explanation:
As according to the offer if you buy 
one candy you can take at most two 
more for free. So in the first case, 
you buy the candy which costs 1 and 
takes candies worth 3 and 4 for free, 
also you buy candy worth 2 as well.
So min cost : 1+2 =3.
In the second case, you can buy the 
candy which costs 4 and takes candies 
worth 1 and 2 for free, also you need 
to buy candy worth 3 as well. 
So max cost : 3+4 =7.

******************************************************************
 vector<int> candyStore(int candies[], int N, int K)
    {
        int mini=0;
        int maxi=0;
        sort(candies,candies+N);
        
        int i=0;
        int j=N-1;
        
        while(i<=j){
            mini+=candies[i];
            i++;
            j=j-K;
        }
        
        i=0;
        j=N-1;
        
        while(i<=j){
            maxi+=candies[j];
            j--;
            i=i+K;
        }
        vector<int >ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
*/