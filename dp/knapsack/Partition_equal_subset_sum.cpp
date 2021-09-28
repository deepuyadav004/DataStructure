Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.
  
  
  code ------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  // code for checking given sum exists or not
    int helper(int sum, int n, int arr[]){
        
        int matrix[n+1][sum+1];
        for(int i=0; i<=n; i++){
            matrix[i][0]=1;
        }
        for(int j=1; j<=sum; j++){
            matrix[0][j]=0;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(j<arr[i-1]){
                    matrix[i][j]=matrix[i-1][j];
                }else{
                    matrix[i][j]=matrix[i-1][j] || matrix[i-1][j-arr[i-1]];
                }
            }
        }
        return matrix[n][sum];
    }

// function to tell equal partition exists or not
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0; i<N; i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return false;
        }
        
        return helper(sum/2,N,arr);
    }
};
