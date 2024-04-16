/*
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }

        int longest=1;// ATLEAST ONE 
       
        unordered_set<int> s;

        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }

        for(auto it :s){// it REFERS TO ELEMENT NOT "i"...
        // WITHOUT THIS IF STATEMENT ..THIS SOLUTION WILL WORK LIKE O(n square)
            if(s.find(it-1)==s.end()){// MAKING SURE THAT ITS STARTING POINT
                  int count=1;
                int x=it;
                while(s.find(x+1)!=s.end()){
                    count++;
                    x++;
                }
            longest=max(longest,count);
            }
          
        }
        return longest;
    }
*/