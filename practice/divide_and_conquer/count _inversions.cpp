Approach: 
Suppose the number of inversions in the left half and right half of the array (let be inv1 and inv2); what kinds of inversions are not accounted for in Inv1 + Inv2? The answer is - the inversions that need to be counted during the merge step. Therefore, to get the total number of inversions that needs to be added are the number of inversions in the left subarray, right subarray, 
and merge().
  
  How to get the number of inversions in merge()? 
In merge process, let i is used for indexing left sub-array and j for right sub-array. At any step in merge(), if a[i] is greater than a[j], then there are (mid – i) inversions.
  because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j]
  
  Algorithm: 
The idea is similar to merge sort, divide the array into two equal or almost equal halves in each step until the base case is reached.
Create a function merge that counts the number of inversions when two halves of the array are merged, create two indices i and j, i is the index for the first half, and j is an
index of the second half. if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted, so all the remaining elements in 
left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
Create a recursive function to divide the array into halves and find the answer by summing the number of inversions is the first half, the number of inversion in the second half 
and the number of inversions by merging the two.
The base case of recursion is when there is only one element in the given half.

  
  long long merge(long long arr[], int l, int m, int r){
        int n1=m-l+1;
        int n2=r-m;
        
        long left[n1];
        long right[n2];
        for(int i=0; i<n1; i++){
            left[i]=arr[l+i];
        }
        for(int j=0; j<n2; j++){
            right[j]=arr[m+1+j];
        }
        
        int i=0,j=0,k=l;
        long count=0;
        while(i<n1 && j<n2){
            if(left[i] <= right[j]){
                arr[k++]=left[i++];
            }else{
                arr[k++]=right[j++];
                count += n1-i;  // bcz left and right subarray are sorted of one inversion is present then it will be present for all elements after that
            }
        }
        
        while(i<n1){
            arr[k++]=left[i++];
        }
        while(j<n2){
            arr[k++]=right[j++];
        }
        return count;
    }
