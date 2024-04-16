/*
class Solution{
    public:
    
 // TIME COMPLEXITY N(square)..CHECKING BALANCE FOR EACH AND EVERY NODE
    int height(Node* root){
        if(root==NULL){
            return 0;
        }
        int left=height(root->left); 
        int right=height(root->right);
        int ans=max(left,right)+1; // MAIN LOGIC
        return ans;
    }
    bool isBalanced(Node *root)
    {
        if(root==NULL){
            return true;
        }
        bool left=isBalanced(root->left);// RECURSIVELY CHECKING EACH NODE
        bool right=isBalanced(root->right);
        bool diff=abs(height(root->left)-height(root->right))<=1;// MAIN LOGIC.. CALLED HEIGHT FUNCTION IN EVERY NODE
        
        return left&& right&& diff;
    }
    **************************************************************************************************************************
    
    pair<bool,int> checkBalance(Node *root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0); 
            return p;
        }
        pair<bool,int> left=checkBalance(root->left);
        pair<bool,int> right=checkBalance(root->right);
        
        pair<bool,int> ans;
        ans.second=max(left.second,right.second)+1;
        
        bool diff=abs(left.second-right.second)<=1;........A tree's height balanced if difference between heights of left 
                                                            and right subtrees is not more than one for all nodes of tree. 
        
        
        if(left.first&&right.first&&diff){
            ans.first=true;
        }
        return ans;
    }
    bool isBalanced(Node *root)
    {
        return checkBalance(root).first;
    }
};
*/