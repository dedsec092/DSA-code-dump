#include<iostream>
using namespace std;
#include<queue>

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;

    }
};

node* buildTree(node* root){

    cout<<"enter the elementL:"<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new node(data);

    cout<<"enter left element"<<endl;
    root->left=buildTree(root->left);

    cout<<"enter rioght element"<<endl;
    root->left=buildTree(root->right);

    return root;


}

void leverOrderTraversal(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inOrder(node*root){
    if(root==NULL){
        return ;
    }

    inOrder(root->left);
    cout<<root->data<<endl;
    inOrder(root->right);
}

void preOrder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node*root){
    if(root==NULL){
        return ;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data;
}
int main(){
    node*root=NULL;

    buildTree(root);
    leverOrderTraversal(root);


    return 0;
}