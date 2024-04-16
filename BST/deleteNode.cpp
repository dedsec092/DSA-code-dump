/*

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key) {
   if(root==NULL){
       return root;
   }
    if(root->data==key){
        //leaf
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        //one child
        
        //left
        if(root->left!=NULL&&root->right==NULL){
            BinaryTreeNode<int>* temp=root->left;
            delete root;
            return temp;
        }
        //right
        if(root->left==NULL&&root->right!=NULL){
            BinaryTreeNode<int>* temp=root->right;
            delete root;
            return temp;
        }
        //two children
        if(root->left!=NULL&&root->right!=NULL){
             BinaryTreeNode<int>*pred=root->left;
             while(pred->right!=NULL){
                 pred=pred->right;
             }
             int predData=pred->data;
             root->data=predData;
             root->left=deleteNode(root->left,  predData);
             return root;
        }
    }
   else if(root->data<key){
        root->right= deleteNode(root->right,key);
    }
    else{
         root->left= deleteNode(root->left,key);
    }
}
*/