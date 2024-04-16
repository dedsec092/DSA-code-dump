/*
QUESTION:
Input :
        1
      /   \
     3     2

Output: 3 2 1
Explanation:
Traversing level 1 : 3 2
Traversing level 0 : 1
******************************************
vector<int> reverseLevelOrder(Node *root)
{
    queue<Node*> q;
    vector<int> ans;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        ans.push_back(temp->data);
        q.pop();
        
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
        
    }
    reverse(ans.begin(),ans.end());
    return ans; 
}
*/