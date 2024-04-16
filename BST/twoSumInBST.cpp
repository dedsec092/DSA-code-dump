/*
void storeBSTelements(BinaryTreeNode<int>* root,vector<int> &inorder){
    if(root==NULL){
        return;
    }
    storeBSTelements(root->left, inorder);
    inorder.push_back(root->data);
    storeBSTelements(root->right, inorder);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> inorder;....USING INORDER TO STORE VALUES IN SORTED MANNER..
    storeBSTelements(root, inorder);
    
    int i=0;.....USING TWO POINTER APPROACH TO GET O(N) TIME COMPLEXITY...
    int j=inorder.size()-1;
    while(i<j){
        int sum=inorder[i]+inorder[j];
        if(sum==target){
            return true;
        }
        else if(sum>target){
            j--;
        }
        else{
            i++;
        }
        
    }
    return false;
}
*/