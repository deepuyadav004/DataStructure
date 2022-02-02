Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.

 

Example 1:

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.
  
  
  Efficient Approach: There is an idea if all the elements of the array are positive. If a subarray has sum greater than the given sum then there is no possibility that adding elements to the current subarray the sum will be x (given sum). Idea is to use a similar approach to a sliding window. Start with an empty subarray, add elements to the subarray until the sum is less than x. If the sum is greater than x, remove elements from the start of the current subarray.
Algorithm:  


Create three variables, l=0, sum = 0
Traverse the array from start to end.
Update the variable sum by adding current element, sum = sum + array[i]
If the sum is greater than the given sum, update the variable sum as sum = sum - array[l], and update l as, l++.
If the sum is equal to given sum, print the subarray and break the loop.
  
  
   vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        
        int i=0,j=0;
        int sum=arr[0];
       for(i=1; i<=n; i++){
           while(sum>s && j<i-1){
               sum-=arr[j];
               j++;
           }
           if(sum==s){
               return {j+1, i};
           }
           if(i<n){
               sum+=arr[i];
           }
       }
       return {-1};
    }
