/*(
Consider the two strings 'P' = "abfyg" and 'Q' = "gabfy" 

If we cyclically rotate String 'P' to the right once. The resulting string P becomes "gabfy" which is equal to String 'Q'. 

Therefore it is possible to convert String 'P' to String 'Q'.
*************************************************************
int isCyclicRotation(string &p, string &q) 
{
    int l1=p.length();
    int l2=q.length();

    if(l1!=l2){
        return 0;
    }

    string temp=p+p;

    if(temp.find(q)!=string::npos){.......npos means-:no position (or)...no mathch...
        return 1;
    }
    else{
        return 0;
    }

}
*******************************************************************
int isCyclicRotation(string &p, string &q) 
{
    int len1=p.length();
    int len2=q.length();
    if(len1!=len2){
        return 0;
    }
    string temp=p+p;
    int find=temp.find(q);
    if(find>=0){
        return 1;
    }
    return 0;
}
)*/