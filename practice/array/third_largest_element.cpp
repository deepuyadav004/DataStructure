Given an array of distinct elements. Find the third largest element in it.

Suppose you have A[] = {1, 2, 3, 4, 5, 6, 7}, its output will be 5 because it is the 3 largest element in the array A.

Example 1:

Input:
N = 5
A[] = {2,4,1,3,5}
Output: 3
  
  
   int thirdLargest(int a[], int n)
    {
         //Your code here
         int no_1=-1, no_2=-1, no_3=-1;
         for(int i=0; i<n; i++){
             if(a[i]>=no_1){
                 no_3=no_2;
                 no_2=no_1;
                 no_1=a[i];
             }else if(a[i]>=no_2){
                 no_3=no_2;
                 no_2=a[i];
             }else if(a[i]>=no_3){
                 no_3=a[i];
             }
         }
         return no_3;
    }
