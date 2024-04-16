/*
// PAIR IS USED TO REDUCE TIME COMPLEXITY..AS WE NEED TO KNOW THE HEIGHT OF THE TREE TO KNOW THE DIAMETER..CALLING A FUNCTION(FOR HEIGHT ) IN DAIMETER FUNCTION WILL RESULT TO O(N square)

COMBINED FUNCTION FOR DAIMETER AND HEIGHT AS HEIGHT IS NEEDED TO FIND DIAMETER
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    pair<int,int> returnDiameter(Node* root){.....In this pain<int,int>..first is diameter and second is height..
        if(root==NULL){
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        pair<int,int> left=returnDiameter(root->left);
        pair<int,int> right=returnDiameter(root->right);
        
        int op1=left.first;.......Maximum daimeter may found in left subtree...
        int op2=right.first;.......................may found in right subtree...
        int op3=left.second+right.second+1;.......combination of left subtree nad right subtree ... taking height(left)+height(right)+1(root)...
        
        pair<int ,int> ans;
        ans.first=max(op1,max(op2,op3));.........Maximum diameter stored...
        ans.second=max(left.second,right.second)+1;
        
        return ans;
    }
    int diameter(Node* root) {
        // Your code here
        return returnDiameter(root).first;
    }
};
*/