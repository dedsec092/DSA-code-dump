/*
void solve(stack<int>&inputStack, int N,int count){
   int mid=N/2;
   if(count==mid){
      inputStack.pop();
      return;
   }

   int temp=inputStack.top();
   inputStack.pop();
   
   solve(inputStack,  N,  count+1);
   inputStack.push(temp);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   int count=0;
   solve(inputStack,N,count);
   
}
*/