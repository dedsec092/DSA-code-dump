/*
Given an array arr of size N containing positive and negative integers. Arrange the array alternatively such that every non-negative integer is followed by a negative integer and vice-versa.

Note:
The number of positive integers and negative integers may not be equal. In such cases, add the extra integers at the end.
For Example:
For array {4, -9, -2, 6, -8}, the output will be {-9, 4, -2, 6, -8}

For array {1, 2, 3, -5}, the output will be {-5, 1, 2, 3}   
***********************************************************************************************************************************************
void rearrange(vector<int> &arr)
{
	int posInd=0;
	int negInd=0;
	int curr=0;
	while(arr[posInd]<0 && posInd<arr.size()){
		posInd++;
	}
		while(arr[negInd]>0 && negInd<arr.size()){
		negInd++;
	}
	while(posInd<arr.size() && negInd<arr.size()){

	
		if(curr%2==0){
			swap(arr[curr],arr[negInd]);
			curr++;
			negInd++;

		}
		else{
			swap(arr[curr],arr[posInd]);
			curr++;
			posInd++;
		}
		
		while(arr[posInd]<0 && posInd<arr.size()){
		posInd++;
	}
        while (arr[negInd] > 0 && negInd < arr.size()) {
                negInd++;
        }
}

}

*/