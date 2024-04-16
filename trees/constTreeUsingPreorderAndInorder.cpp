/*
class Solution{
    public:
    
     int findPosition(int in[],int element,int n){
         for(int i=0;i<n;i++){
             if(in[i]==element){
                 return i;
             }
             
         }
         return -1;
     }
    Node* solve(int in[],int pre[], int n,int &i,int inorderStart,int inorderEnd){
        if(i>=n || inorderStart>inorderEnd){
            return NULL;
        }
        int element=pre[i++];
        Node*root=new Node(element);
        int position=findPosition(in,element,n);
        
        root->left=solve(in,pre,n,i,inorderStart,position-1);
        root->right=solve(in,pre,n,i,position+1,inorderEnd);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preI=0;
        Node*ans=solve(in,pre,n,preI,0,n-1);
        return ans;
    }
};

******************************************************************

APPROACH 2:- USING MAP.... MORE OPTIMISED....

 void creatMap(int in[], map<int,int> &InorderMap,int n){
         for(int i=0;i<n;i++){
             InorderMap[in[i]]=i;
         }
     }
    Node* solve(int in[],int pre[],  map<int,int> &InorderMap,int n,int &i,int inorderStart,int inorderEnd){
        if(i>=n || inorderStart>inorderEnd){
            return NULL;
        }
        int element=pre[i++];
        Node*root=new Node(element);
        int position=InorderMap[element];
        
        root->left=solve(in,pre,InorderMap,n,i,inorderStart,position-1);
        root->right=solve(in,pre,InorderMap,n,i,position+1,inorderEnd);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preI=0;
        map<int,int> InorderMap;
        creatMap(in,InorderMap,n);
        Node*ans=solve(in,pre,InorderMap,n,preI,0,n-1);
        return ans;
    }
};
*/

