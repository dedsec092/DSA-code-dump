/*
BST TO MAX HEAP IS JUST LIKE CONVERTING INORDER TO POSTORDER....

class Solution{
  public:
  void inorderVals(Node*root, vector<int>& inorder){
      if(root==NULL){
          return ;
      }
      inorderVals(root->left,inorder);
      inorder.push_back(root->data);
      inorderVals(root->right,inorder);
  }
  void toPostorder(Node*root, vector<int>& inorder,int &index){
      if(root==NULL){
          return;
      }
      
      toPostorder(root->left,inorder,index);
      toPostorder(root->right,inorder,index);
      root->data=inorder[index++];
  }
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> inorder;
        inorderVals(root,inorder);
        int index=0;
        toPostorder(root,inorder,index);
    }    
};
*/