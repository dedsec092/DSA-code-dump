/*
Input:
S = "0100110101"
Output: 4
Explanation: 
The required substrings are 01, 0011, 01 and 01.
**********************************************************
 int maxSubStr(string str){
        int count0 = 0, count1 = 0;
 
    int ans = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '0') {
            count0++;
        }
        if(str[i]=='1') {
            count1++;
        }
        if (count0 == count1) {
            ans++;
        }
    }
 
    if (count0!=count1) {
        return -1;
    }
 
    return ans;
    }
*/