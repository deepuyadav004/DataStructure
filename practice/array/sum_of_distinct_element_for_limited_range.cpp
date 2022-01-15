Given an array, arr[] of N elements such that every element of the array is an integer in the range 1 to n, the task is to find the sum of all the distinct elements of the array.


Example 1:

Input: N = 9
arr[] = {5, 1, 2, 4, 6, 7, 3, 6, 7}
Output: 28
Explanation: The distinct elements in 
the array are 1, 2, 3, 4, 5, 6, 7.
  
  
  // best solution int sumOfDistinct(int arr[], int n) 
	{ 
	    int sum = 0; 
	    for (int i = 0; i < n; i++) { 
	      
	        // If element appears first time 
	        if (arr[abs(arr[i]) - 1] >= 0) { 
	            sum += abs(arr[i]); 
	            arr[abs(arr[i]) - 1] *= -1; 
	        } 
	    } 
	    return sum; 
	} 


// anotehr approach its a general approach

int findSum(int arr[],int n)
{
    int sum = 0;

    // Hash to store all element of array
    unordered_set< int > s;
    for (int i=0; i<n; i++)
    {
        if (s.find(arr[i]) == s.end())
        {
            sum += arr[i];
            s.insert(arr[i]);
        }
    }

    return sum;
}
Time Complexity : O(n log n) 
Space Complexity : O(1)
