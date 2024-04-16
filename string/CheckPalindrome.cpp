/*
class Solution {
public:
    bool valid(char ch){
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>=0&&ch<=9)){
            return true ;

        }
        return false;
    }
    char toLowerCase(char ch){
        if(ch>='a'&&ch<='z'){
            return ch;
        }
        else{
            char temp= ch-'A'+'a';
            return temp;
        }
    }
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.length();i++){
            if(valid(s[i])){
                temp.push_back(s[i]);
            }
        }
        for(int i=0;i<temp.length();i++){
           temp[i]= toLowerCase(temp[i]);
        }
        int st=0;
        int e=temp.length()-1;
        while(st<e){
            if(temp[st]!=temp[e]){
                return false;
            }
            else{
                st++;
                e--;
            }
           
        }
         return true;

    }
};
*/