// Given an array Arr of size N containing positive integers. Find the maximum sum of a subsequence such that no two numbers in the sequence should be adjacent in the array.

// Example 1:

// Input:
// N = 6
// Arr[] = {5, 5, 10, 100, 10, 5}
// Output: 110
// Explanation: If you take indices 0, 3
// and 5, then Arr[0]+Arr[3]+Arr[5] =
// 5+100+5 = 110.
// Example 2:

// Input:
// N = 4
// Arr[] = {3, 2, 7, 10}
// Output: 13
// Explanation: 3 and 10 forms a non
// continuous  subsequence with maximum
// sum.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findMaxSum() which takes the array of integers arr and n as parameters and returns an integer denoting the answer.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 106
// 1 ≤ Arri ≤ 107



	int findMaxSum(int *arr, int n) {
	    // code here
	    int inc=arr[0];
	    int exc=0;
	    int new_exc;
	    
	    for(int i=1; i<n; i++){
	        new_exc=exc > inc ? exc:inc;
	        
	        inc=max(exc+arr[i], inc);
	        exc=new_exc;
	    }
	    return max(inc, exc);
	}


// ------------------------------------------------------ method 2-------------------------------------------------------------------

	int findMaxSum(int *arr, int n) {
	    // code here
	    int inc=arr[0];
	    int exc=0;
	    int new_exc;
	    
	    for(int i=1; i<n; i++){
	        new_exc=exc > inc ? exc:inc;
	        
	        inc=max(exc+arr[i], inc);
	        exc=new_exc;
	    }
	    return max(inc, exc);
	}
