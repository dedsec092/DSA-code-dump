/*
QUESTION:Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. 
Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.

APPROACH: MAKE A HUFFMAN TREE USING MINHEAP AND TRAVERSE THE HUFFMAN TREE PLACE 0 AT LEFT AND 1 AT RIGHT 

class Solution
{
    
	public:// MAKING OF TREE
	class Node{
	    public:
	    int data;
	    Node* left;
	    Node* right;
	    
	    Node(int data){
	        data=data;
	        left=NULL;
	        right=NULL;
	    }
	};
	
	class cmp{
	    public:
	    bool operator()(Node* a,Node* b){
	        return a->data > b->data;
	    }
	};
	
	void traverseTree(Node* root,	vector<string> &ans,string temp){
	    if(root->left==NULL && root->right==NULL){
	        ans.push_back(temp);
	        return ;
	    }
	    traverseTree(root->left,ans,temp+'0');
	    traverseTree(root->right,ans,temp+'1');
	}
	
	
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*,vector<Node*>,cmp > minHeap;
		    
		    for(int i=0;i<N;i++){
		        Node* temp= new Node(f[i]);
		        minHeap.push(temp);
		    }
		
		
		while(minHeap.size()>1){// THE REMAINING ELEMENT WILL BE ROOT OF HUFFMAN TREE
		    Node* left=minHeap.top();
		    minHeap.pop();
		    
		    Node* right=minHeap.top();
		    minHeap.pop();
		    
		    Node* newNode= new Node(left->data+ right->data);
		    newNode->left=left;
		    newNode->right=right;
		    
		    minHeap.push(newNode);
		}
		
		Node* root=minHeap.top();
		
			vector<string> ans;
			string temp="";// WILL BE PUSHED IN ANS WHILE TRAVERSING HUFFMAN TREE
			
		traverseTree(root,ans,temp);
		return ans;
		}	
};
*/