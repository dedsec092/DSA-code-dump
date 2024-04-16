/*
class SpecialStack {
    public:
        stack<pair<int,int>> s;
        int mini=INT_MAX;

    void push(int data) {
        mini=min(mini,data);
        s.push(make_pair(data,mini));
    }

    void pop() {
        s.pop();
        if(!s.empty()){
            mini=s.top().second;
        }
        else{
            mini=INT_MAX;
        }
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }  
};
*/