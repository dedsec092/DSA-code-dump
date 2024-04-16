/*
   vector <int> zigZagTraversal(Node* root)
    {
    	bool leftToRight=true; // FLAG
    	queue<Node*> q;
    	q.push(root);
    	vector<int> ans;
    	
    	while(!q.empty()){
    	    int size=q.size();
    	    vector<int> level;// STORING LEVEL WISE(RE INITIALISED IN EACH ITERATION)
    	    
    	    while(size--){// TRAVERSING LEVEL
    	        Node* front=q.front();
    	        q.pop();
    	        level.push_back(front->data);
    	        
    	        if(front->left){
    	            q.push(front->left);
    	        }
    	        if(front->right){
    	            q.push(front->right);
    	        }
    	    }
    	    
    	    if(leftToRight==false){ 
    	        reverse(level.begin(),level.end());// MAKING A LEVEL RIGHT TO LEFT 
    	    }
    	    
    	    for(auto i: level){
    	        ans.push_back(i);
    	    }
    	    
    	    leftToRight=!leftToRight;// FLIPPING THE FLAG AFTER EACH LEVEL
    	    
    	}
    	return ans;
    }
*/