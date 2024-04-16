/*
APPROACH-: SAVING INORDER VALS IN ARRAY OF GIVEN BSTs..
merging the inorder vals arrays..
converting that merged array and making it a BST..



void inorderVals(TreeNode *root,vector<int> &x){...saving inorder of given BSTs
    if(root==NULL){
        return;
    }
    inorderVals( root->left,  x);
    x.push_back(root->data);
    inorderVals( root->right,  x);
}
vector<int> mergeArray(vector<int> &a,vector<int> &b){...merging two inorderVal arrays to find the INORDER OF MERGED ARRAY
    vector<int> arr(a.size()+b.size());
    int i=0,j=0,k=0;
    while(i<a.size()&&j<b.size()){
        if(a[i]<b[j]){
            arr[k++]=a[i];
            i++;
        }
        else{
             arr[k++]=b[j];
            j++;
        }
    }
    while(i<a.size()){
         arr[k++]=a[i];
            i++;
    }
    while(j<b.size()){
         arr[k++]=b[j];
            j++;
    }
    return arr;

}
TreeNode * inorderToBST(int s,int e, vector<int> mergeArr){...INORDER VALUES TO BST...
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    TreeNode *root=new TreeNode(mergeArr[mid]);
    root->left=inorderToBST( s,  mid-1, mergeArr);
    root->right=inorderToBST( mid+1,  e,  mergeArr);

    return root; 
}
TreeNode * mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> a,b;
    inorderVals(root1,  a);
    inorderVals( root2,  b);
    vector<int> mergeArr= mergeArray(a,b);
    return inorderToBST(0,  mergeArr.size()-1,  mergeArr);
}

************************************************************************************
APPROACH 2....more optimized......because ..array is replaced with Linked List..with constant space complexity..

TIME COMPLEXITY O(m+n)...m for first BST and n for second BST...


 void BSTtoLL(TreeNode *root,TreeNode *&head){
    if(root==NULL){
        return ;
    }
    BSTtoLL(root->right,  head);....recursion will do...
    root->right=head;

    if(head!=NULL)
    head->left=root;

    head=root;
    BSTtoLL(root->left,head);
}
 TreeNode * mergeLL( TreeNode *&head1, TreeNode *&head2){
      TreeNode *head=NULL;
       TreeNode *tail=NULL;

       while(head1!=NULL&&head2!=NULL){
           if(head1->data<head2->data){
               if(head==NULL){
                   head=head1;
                   tail=head1;
                   head1=head1->right;
               }
               else{
                   tail->right=head1;
                    head1->left=tail;
                    tail=head1;
                    head1=head1->right;
               }
           }
           else{
                if(head==NULL){
                   head=head2;
                   tail=head2;
                   head1=head2->right;
               }
               else{
                   tail->right=head2;
                    head2->left=tail;
                    tail=head2;
                    head2=head2->right;
               }
           }
       }
       while(head1!=NULL){
            tail->right=head1;
                    head1->left=tail;
                    tail=head1;
                    head1=head1->right;
       }
       while(head2!=NULL){
            tail->right=head2;
                    head2->left=tail;
                    tail=head2;
                    head2=head2->right;
       }
 }
int countNodes(TreeNode *&head){
    int count=0;
    TreeNode *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->right;
    }
    return count;
}
 TreeNode *convertLLtoBST(TreeNode *&head,int n){

     if(n<=0||head==NULL){
         return NULL;
     }
     
     TreeNode *left=convertLLtoBST(head,  n/2);
     TreeNode *root=head;
     root->left=left;

     head=head->right;
     root->right=convertLLtoBST(head,  n-n/2-1);
    return root;
 }

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    TreeNode *head1;
    TreeNode *head2;
    BSTtoLL( root1,  head1);
    BSTtoLL(root2,  head2);
    TreeNode *head=mergeLL( head1,  head2);
    int n=countNodes( head);
    return convertLLtoBST(head,n);
}

*/