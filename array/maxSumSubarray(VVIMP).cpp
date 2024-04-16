/*
long long maxSubarraySum(vector<int> arr, int n)
{
    long long int sum=0;
    long long int maxSum=INT_MIN;

    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum>maxSum){
            maxSum=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxSum;
}
*/