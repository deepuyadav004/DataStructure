Given an array arr[] of N distinct numbers, the task is to sort all even-placed numbers in increasing and odd-place numbers in decreasing order. 
  The modified array should contain all sorted even-placed numbers followed by reverse sorted odd-placed numbers.
Note that the first element is considered as even because of its index 0.

Example 1:

Input: N = 8
arr[] = {0, 1, 2, 3, 4, 5, 6, 7}
Output: 0 2 4 6 7 5 3 1
Explanation: 
Even-place elements : 0, 2, 4, 6
Odd-place elements : 1, 3, 5, 7
Even-place elements in increasing order : 
0, 2, 4, 6
Odd-Place elements in decreasing order : 
7, 5, 3, 1
  
  
  
  
  	void bitonicGenerator(int arr[], int n)
	{
		// Your code goes here
		int odd=1, even=n-1;
		if(n%2==0){
		    even=n-2;
		}
		while(odd < even){
		    swap(arr[odd], arr[even]);
		    odd += 2;
		    even -= 2;
		}
		sort(arr, arr+(n+1)/2);
		sort(arr+(n+1)/2, arr+n, greater<int>());
	}
		 
