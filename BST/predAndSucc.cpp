/*
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    TreeNode *temp=root;
    int pred=-1;
    int succ=-1;
    
    while(temp->data!=key){
        if(temp->data>key){
            succ=temp->data;...possible succ because succ comes from right and it should be bigger then curren temp->data..
            temp=temp->left;
        }
        else{
            pred=temp->data;...possible pred because pred comes from left and it should be smaller then curren temp->data..
            temp->right;
        }
    }
    TreeNode *leftTree=temp->left;
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;..rightmost value from left tree.
    }
    TreeNode *rightTree=temp->right;
    while(rightTree!=NULL){
        succ=rightTree->data;
        rightTree=rightTree->left;..leftmost value from right tree.
    }
    pair<int,int> ans=make_pair(pred,succ);
    return ans;
}
*/