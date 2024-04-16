/*
class Solution {
public:

    void goLeft(Node*root, vector<int> &ans){
        if(root==NULL||root->left==NULL&&root->right==NULL){
            return;
        }
         ans.push_back(root->data);
        if(root->left){
            goLeft(root->left,ans);
           
        }
        else{
            goLeft(root->right,ans);
            
        }
    }
    
    void storeLeaves(Node*root, vector<int> &ans){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL&&root->right==NULL){
            ans.push_back(root->data);
        }
        
        storeLeaves(root->left,ans);
        storeLeaves(root->right,ans);
    }
    
    void goReverseRight(Node*root,vector<int> &ans){
        if(root==NULL||root->left==NULL&&root->right==NULL){
            return;
        }
        
        if(root->right){
            goReverseRight(root->right,ans);
        }
        else{
            goReverseRight(root->left,ans);
            
        }
        ans.push_back(root->data);
    }
    
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        
        goLeft(root->left,ans);
        
        storeLeaves(root->left,ans);
        storeLeaves(root->right,ans);
        
        goReverseRight(root->right,ans);
        
        return ans;
    }
};
*/