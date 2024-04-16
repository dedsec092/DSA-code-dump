/*
USING INORDER TRAVERSAL...

int solve(BinaryTreeNode<int>* root,int &i,int k){
    if(root==NULL){
        return -1;
    }
    //left
    int left=solve(root->left, i,k);
    if(left!=-1){
        return left;
    }

    //node or root
    i++;..........while returning from null to node i++...
    if(i==k){
        return root->data;
    }
    //right
    return solve(root->right, i,k);

}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i=0;
    return solve(root,i,k);

}
*/