Given an array Arr (distinct elements) of size N. Rearrange the elements of array in zig-zag fashion. The converted array should be in form a < b > c < d > e < f.
  The relative order of elements is same in the output i.e you have to iterate on the original array only.

Example 1:

Input:
N = 7
Arr[] = {4, 3, 7, 8, 6, 2, 1}
Output: 3 7 4 8 2 6 1
Explanation: 3 < 7 > 4 < 8 > 2 < 6 > 1
  
  // first
  
  void zigZag(int arr[], int n) {
	   
	    
	    // Traverse through array and jump i         //by 2 as after every 2 times we are //comparing if it satisfies  "<>" Condition
	    
	    for (int i =1; i<n; i+=2){
	        
	   // if i is less than equal to last //element + condition

	      if (i<=n && arr[i]<arr[i-1]) 
	     {
	         swap(arr[i],arr[i-1]);
	         
	     }
// if i is less than last element+ condition
	        if(i<n-1 && arr[i]<arr[i+1]) 
	        {
	            swap(arr[i],arr[i+1]);
	        }

	    }
	}

// second 

	void zigZag(int arr[], int n) {
	    // code here
	    for(int i=0; i<n-1; i++){
	        if(i%2==0){
	            if(arr[i] > arr[i+1]){
	                swap(arr[i], arr[i+1]);
	            }
	        }else{
	            if(arr[i]<arr[i+1]){
	                swap(arr[i], arr[i+1]);
	            }
	        }
	    }
	}
