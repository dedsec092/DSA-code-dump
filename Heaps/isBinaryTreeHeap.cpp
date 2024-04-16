/*
class Solution {
  public:
  // count total nodes...
  int count(struct Node* root){
      if(root==NULL){
          return 0;
      }
      int ans=1+count(root->left)+count(root->right);
      return ans;
  }

  //checking if 2*i+1(left) and 2*i+2(right) is in range of n...


  bool isCBT(struct Node*root,int i,int n){//...n is total nodes in tree..
     if(root==NULL){
         return true;
     }
    if(i>=n){
        return false;
    }
    bool left=isCBT(root->left,2*i+1,n);
    bool right=isCBT(root->right,2*i+2,n);
    
    return (left&&right);
  }


  //checking conditions of max heap...


  bool isMax(struct Node* root){
      if(root->left==NULL&&root->right==NULL){
          return true;
      }
      if(root->right==NULL){
          return root->left->data<root->data;
      }
      else{
          bool left=isMax(root->left);
          bool right=isMax(root->right);
          
          return (left&&right&&(root->data>root->left->data&&root->data>root->right->data));
      }
  }

  
    bool isHeap(struct Node* tree) {
        int i=0;
        int n=count(tree);
        if(isCBT(tree,i,n)&&isMax(tree)){
            return true ;
        }
        else{
            return false;
        }
    }
};
*/