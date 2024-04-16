/*
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root==NULL){
        return false;
    }
    
    if(root->data==x){
        return true;
    }
    else if(root->data<x){
        return searchInBST(root->right,x);
    }
    else  {
         return searchInBST(root->left,x);
    }
   
}

*****************************************************************************************

ITERATIVE APPROACH WITH CONSTANT SPACE COMPLEXITY:-

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *temp=root;
    while(temp!=NULL){
        if(temp->data==x){
            return true;
        }
        else if (temp->data<x){
            temp=temp->right;
        }
        else {
            temp=temp->left;
        }
    }
    return false;
}
*/