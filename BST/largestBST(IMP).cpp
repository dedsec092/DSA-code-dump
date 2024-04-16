/*
//it can be a partial BST too so we have to return the largest "partial" BST..


class info{//....using this class to keep track and not visit a singel node multiple times..
    public ://...this class helps us to attain O(n) time complexity..
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode<int>* root,int &maxSize){
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};//..INT_MIN for maxi and INT_MAX for mini..
    }
    info left=solve(root->left,maxSize);//...retrieving all the infos of all the nodes..
    info right=solve(root->right,maxSize);//...

    info currNode;//...we will check the infos to check BST 
                    
    currNode.maxi=max(root->data,right.maxi);
    currNode.mini=min(root->data,left.mini);
    currNode.size=left.size+right.size+1;

    if(left.isBST==true&&right.isBST==true&&(root->data>left.maxi&&root->data<right.mini)){
        currNode.isBST=true;
    }
    else{
        currNode.isBST=false;
    }
    if(currNode.isBST){
        maxSize=max(maxSize,currNode.size);
    }
    return currNode;

}
int largestBST(TreeNode<int>* root) 
{
    int maxSize;
    info temp=solve(root,maxSize);
    return maxSize;
}
*/