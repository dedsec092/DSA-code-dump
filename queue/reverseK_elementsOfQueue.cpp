/*
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;
    for(int i=0;i<k;i++){
        int val=q.front();
        q.pop();
        s.push(val);
        
    }
    while(!s.empty()){
        int t=s.top();
        s.pop();
        q.push(t);
    }
    
    int x=q.size()-k;
    
    while(x!=0){
        int val=q.front();
        q.pop();
        q.push(val);
        x--;
    }
    return q;
}
*/