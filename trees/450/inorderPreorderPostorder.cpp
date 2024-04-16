/*
void inorderT(TreeNode *root, vector<int> &inorder){
    if(root==NULL){
        return;
    }
    inorderT(root->left,inorder);
    inorder.push_back(root->data);
    inorderT(root->right, inorder);

}
void preorderT(TreeNode *root, vector<int> &preorder){
    if(root==NULL){
        return;
    }
     preorder.push_back(root->data);
    preorderT(root->left,preorder);
   
    preorderT(root->right, preorder);

}
void postorderT(TreeNode *root, vector<int> &postorder){
    if(root==NULL){
        return;
    }
     
    postorderT(root->left,postorder);
   
    postorderT(root->right, postorder);
    postorder.push_back(root->data);

}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> ans;
    vector<int>inorder;
    inorderT(root,inorder);
    vector<int> preorder;
    preorderT(root,preorder);
     vector<int> postorder;
     postorderT(root,postorder);
     ans.push_back(inorder);
     ans.push_back(preorder);
     ans.push_back(postorder);
     return ans;

}
*/