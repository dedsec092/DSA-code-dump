/*
Input:
S = i.like.this.program.very.much
Output: 
much.very.program.this.like.i

APPROACH:
string reverseWords(string S) 
    { 
        string ans="";
        string temp="";// using temp string for reversals
        
        for(int i=S.length()-1;i>=0;i--){
            if(S[i]=='.'){
                reverse(temp.begin(),temp.end());
               ans=ans+temp;// concatenating temp with ans(push_back doesnt work here)
                temp="";
                ans=ans+'.';
            }
            else{
                temp.push_back(S[i]);
            }
        }
        reverse(temp.begin(),temp.end());
               ans=ans+temp;
        
        return ans;
    } 
*/