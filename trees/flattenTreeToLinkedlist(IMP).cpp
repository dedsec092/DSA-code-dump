/*
class Solution
{.....USING MORRIS TRAVERSAL....TO GET O(1) SPACE COMPLEXITY...
.......PREORDER MORRIS TRAVERSAL ....GOING LEFT AND FINDING PREDECESSER THERE...
    public:
    void flatten(Node *root)
    {
        Node*curr=root;
        while(curr!=NULL){
            if(curr->left){
                Node*pred=curr->left;
                while(pred->right){
                    pred=pred->right;
                }
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};
*/