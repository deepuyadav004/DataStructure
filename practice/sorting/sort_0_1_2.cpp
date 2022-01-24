Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.



void sort012(int a[], int n)
    {
        // coode here 
        int lo=0;
        int hi=n-1;
        int mid=0;
         
         while(mid <= hi){
             switch(a[mid]){
                 case 0:
                 swap(a[lo++], a[mid++]);
                 break;
                 
                 case 1:
                 mid++;
                 break;
                 
                 case 2:
                 swap(a[mid], a[hi--]);
                 break;
             }
         }
    }
