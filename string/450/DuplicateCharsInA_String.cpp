/*
vector<pair<char,int>> duplicate_char(string s, int n){
        map<char,int> mapping;// UNORDERED MAP CANNOT BE USED HERE(FOR SEQUENCE)
        for(int i=0;i<n;i++){
            mapping[s[i]]++;
        }
        vector<pair<char,int>> ans;
       for(auto i: mapping){// USE AUTO FOR LOOP TO TRAVERSE MAP
           if(i.second>1){
               pair<char,int> temp(i.first,i.second);
               ans.push_back(temp);
           }
       }
       return ans;
}
*/