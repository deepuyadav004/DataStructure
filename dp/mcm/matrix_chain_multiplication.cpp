// recursive code

// Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

// The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

// Example 1:

// Input: N = 5
// arr = {40, 20, 30, 10, 30}
// Output: 26000
// Explaination: There are 4 matrices of dimension 
// 40x20, 20x30, 30x10, 10x30. Say the matrices are 
// named as A, B, C, D. Out of all possible combinations,
// the most efficient way is (A*(B*C))*D. 
// The number of operations are -
// 20*30*10 + 40*20*10 + 40*10*30 = 26000.


// recursive code

 int matrixMultiplication(int N, int arr[])
    {
        // code here
        int i=1;
        return helper(arr,i,N-1);
    }
    
    int helper(int arr[], int i, int j){
        if(i >= j){
            return 0;
        }
        
        int ans=INT_MAX;
        for(int k=i; k<j; k++){
            int temp=helper(arr,i,k)+helper(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            
            ans=min(ans, temp);
        }
        return ans;
    }


// mcm memoize

class Solution{
    int t[501][501];
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int i=1;
        memset(t,-1,sizeof(t));
        return helper(arr, i, N-1);
    }
    
    int helper(int arr[], int i, int j){
        if(i>=j){
            return 0;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        int ans=INT_MAX;
        for(int k=i; k<j; k++){
            int temp=helper(arr,i,k)+helper(arr,k+1,j)+arr[i-1]*arr[j]*arr[k];
            ans=min(ans, temp);
        }
        return t[i][j]=ans;
    }
