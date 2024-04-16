/*
QUESTION:
Input:
  2
   \
    1
   /
 3
Output: 3   

***************************************
int height(struct Node* node){
        if(node==NULL){// BASE CASE
            return 0;
        }
        int leftHeight=height(node->left);
        int rightHeight=height(node->right);
        
        //RECURSION CAN FIND OUT WHICH SUB SUBTREE IS BIGGER (LEFT OR RIGHT)
        if(leftHeight>rightHeight){
            return leftHeight+1;// +1 FOR ROOT
        }
        else{
            return rightHeight+1;
        }
    }
    *************************************************************
    (OR)
    int height(struct Node* node){
        if(node==NULL){// BASE CASE
            return 0;
        }
        int leftHeight=height(node->left);
        int rightHeight=height(node->right);
        
        int ans=max(leftHeight,rightHeight)+1;
        return
    }
*/