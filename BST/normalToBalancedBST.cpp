/*
APPROACH-: TAKING UNBALANCED BST AS INPUT AND SAVING ITS INORDER TRAVERSAL VALUES
THEN CREATING A NEW BALANCED TREE USING INORDER VALUES....

void saveInordervals(TreeNode<int>*root, vector<int> &inorder){
    if(root==NULL){
        return;
    }
    saveInordervals(root->left,  inorder);
    inorder.push_back(root->data);
    saveInordervals(root->right,  inorder);
}
TreeNode<int>* balancing(vector<int> &inorder,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    TreeNode<int>*root=new TreeNode<int>(inorder[mid]);....MAKING OF BALANCED BST USING INORDER VALUES..
    root->left=balancing(inorder, s,mid-1);
    root->right=balancing(inorder,  mid+1,e);
    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorder;
    saveInordervals(root,  inorder);

    return balancing(inorder,  0, inorder.size()-1);
}
*/