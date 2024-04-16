/*
class Solution {
  public:
  Node*createMap(  map<Node*,Node*> &nodeToParent, Node*root,int target){
      nodeToParent[root]=NULL;
      queue<Node*>q;
      q.push(root);
      Node*res=NULL;
      
      while(!q.empty()){
          Node*front=q.front();
          
          q.pop();
          if(front->data==target){
              res=front;
          }
          if(front->left){
              
              nodeToParent[front->left]=front;
              q.push(front->left);
          }
          if(front->right){
               nodeToParent[front->right]=front;
               q.push(front->right);
          }
      }
      return res;
  }
  
  int burn(map<Node*,Node*>nodeToParent,Node*Target){
      int time=0;
      map<Node*,bool>visited;
      visited[Target]=true;
      queue<Node*>q;
      q.push(Target);
      
      while(!q.empty()){
          bool flag=false;
          int size=q.size();
          for(int i=0;i<size;i++){...THIS FOR LOOP IS TO BURN ALL NEIGHORING NODES..
               Node*front=q.front();// imp step..assign front here inside for loop
                q.pop();
              if(front->left&&!visited[front->left]){
                  flag=true;
                  visited[front->left]=true;
                  q.push(front->left);
              }
               if(front->right&&!visited[front->right]){
                  flag=true;
                  visited[front->right]=true;
                  q.push(front->right);
              }
              if(nodeToParent[front]&&!visited[nodeToParent[front]]){
                  flag=true;
                  visited[nodeToParent[front]]=true;
                  q.push(nodeToParent[front]);
              }
              
          }
         if(flag==true){
             time++;
         } 
      }
      return time;
  }
  
    int minTime(Node* root, int target) 
    {
        STEP 1-  Create map for node to parent for going above ..
        STEP 2- find target node..
        STEP 3- BURN
        
        map<Node*,Node*>nodeToParent;
        Node*Target=createMap(nodeToParent,root,target);
        int ans=burn(nodeToParent,Target);
        return ans;
        
       
        
    }
};

*/
