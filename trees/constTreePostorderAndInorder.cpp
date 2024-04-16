/*
void createInorderI(int in[], map<int ,int> &inorderI,int n){
    for(int i=0;i<n;i++){
        inorderI[in[i]]=i;
    }
}

Node* solve(int in[], int post[], int n,int &i,map<int ,int> &inorderI,int inorderS,int inorderE){
    if(i<0||inorderS>inorderE){
        return NULL;
    }
    int element=post[i--];
    Node*root=new Node(element);
    int position=inorderI[element];
    
    root->right=solve(in,post,n,i,inorderI,position+1,inorderE);
    root->left=solve(in,post,n,i,inorderI,inorderS,position-1);
    
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    int i=n-1;
    map<int ,int> inorderI;
    createInorderI(in,inorderI,n);
    Node* ans=solve(in,post,n,i,inorderI,0,n-1);
    
    return ans;
}
*/