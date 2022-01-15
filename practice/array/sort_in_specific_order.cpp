Given an array A of positive integers. Your task is to sort them in such a way that the first part of the array contains odd numbers sorted in descending order,
rest portion contains even numbers sorted in ascending order.

 

Example 1:

Input:
N = 7
Arr = {1, 2, 3, 5, 4, 7, 10}
Output:
7 5 3 1 2 4 10
Explanation:
Array elements 7 5 3 1 are odd
and sorted in descending order,
whereas 2 4 10 are even numbers
and sorted in ascending order.
  
  
   void sortIt(long long arr[], long long n)
    {
        //code here.
        sort(arr, arr+n);
        long long i=0; 
        long long j=n-1;
        while(i < j){
            if(arr[i]%2==0){
                swap(arr[i], arr[j]);
                j--;
            }else{
                i++;
            }
            
        }
        if(arr[i]%2 != 0){
            i++;
        }
        
        
        sort(arr, arr+i, greater<int>());
        sort(arr+i, arr+n);
    }
