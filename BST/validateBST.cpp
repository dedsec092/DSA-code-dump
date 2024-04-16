/*
USING RANGE LIKE -INFINITY OR +INFINITY.. NB-
bool isBST(BinaryTreeNode<int>* root,int min,int max){
    if(root==NULL){
        return true;
    }
    if (root->data >min && root->data < max) {
       
        bool left = isBST(root->left, min, root->data);.....recursion range -infinity(left) to root->data
         bool right = isBST(root->right, root->data, max);..recursion range root->data to +infinity..
        return right&&left;
    }
    else{
        return false;
    }

}
bool validateBST(BinaryTreeNode<int>* root) 
{
    int min=INT_MIN;
    int max=INT_MAX;
    return isBST(root,min,max);
}
*/