/*
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        map<int ,int> bottomView;
        queue<pair<Node*,int> >q;
        q.push( make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> temp=q.front();
            q.pop();
            Node*frontNode=temp.first;
            int numberLine=temp.second;
            
            bottomView[numberLine]=frontNode->data;.......this step is the only difference b/w topview and bottomview....here we overwrite the map with new frontNode->data 
                                                                                                                            to reach the bottom....
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,numberLine-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,numberLine+1));
            }
        }
        
        for(auto i:bottomView){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};
*/