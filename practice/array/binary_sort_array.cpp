Given a binary array A[] of size N. The task is to arrange the array in increasing order.

Note: The binary array contains only 0  and 1.

Example 1:

Input:
N = 5
A[] = {1,0,1,1,0}
Output: 0 0 1 1 1
  
  
  // ----------------------------------------------------------- first approact -------------------------------------------------------------------------------------
  
  1) Count the number of 0s. So let's understand with an example we have an array arr = [0, 1, 0, 1, 0, 0, 1] the size of the array is 7 now we will traverse the entire array 
  and find out the number of zeros in the array, In this case the number of zeros is 4 so now we can easily get the number of Ones in the array by Array Length - Number Of Zeros.





2) Once we have counted, we can fill the array first we will put the zeros and then ones (we can get number of ones by using above formula).
Time Complexity : O(n) 
  
    vector<int> SortBinaryArray(vector<int> arr)
    {
        // Your code goes here 
        int zeros=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==0){
                zeros++;
            }
        }
        
        for(int i=0; i<arr.size(); i++){
            if(i<zeros){
                arr[i]=0;
            }else{
                arr[i]=1;
            }
        }
        return arr;
    }

//------------------------------------------------------------------------- second approact -------------------------------------------------------------------------


Method 2 (Use two indexes to traverse) 
Maintain two indexes. Initialize the first index left as 0 and second index right as n-1.
Do following while left < right 
a) Keep incrementing index left while there are 0s at it 
b) Keep decrementing index right while there are 1s at it 
c) If left < right then exchange arr[left] and arr[right]
 vector<int> SortBinaryArray(vector<int> b)
    {
        // Your code goes here 
        int i=0;
        int j=b.size()-1;
        while(i < j){
            if(b[i]==0){
                i++;
            }else{
                swap(b[i], b[j]);
            }
            
            if(b[j]==1){
                j--;
            }else{
                swap(b[i], b[j]);
            }
        }
        return b;
    }


//---------------------------------------------------------- method 3 -----------------------------------------------------------------------

Another approach : 
1. Take two pointer type0(for element 0) starting from beginning (index = 0) and type1(for element 1) starting from end (index = array.length-1). 
Initialize type0 = 0 and type1 = array.length-1 
2. It is intended to Put 1 to the right side of the array. Once it is done, then 0 will definitely towards the left side of the array.

 vector<int> SortBinaryArray(vector<int> b)
    {
        // Your code goes here 
        int i=0;
        int j=b.size()-1;
        while(i < j){
            if(b[i] == 1){
                swap(b[i], b[j]);
                j--;
            }else{
                i++;
            }
        }
        return b;
    }
