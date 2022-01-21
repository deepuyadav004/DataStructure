Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K. 
  The task is to find the index of the given element K in the array A.

Example 1:

Input:
N = 9
A[] = {5 6,7,8,9,10,1,2,3}
K = 10
Output: 5
Explanation: 10 is found at index 5.
  
  
  int Search(vector<int> vec, int k) {
    //code here
    int start=0;
    int end=vec.size()-1;
    
    while(start <= end){
        int mid=(start+end)/2;
        if(vec[mid]==k){
            return mid;
        }
        
        if(vec[start]<vec[mid]){
            if(k>=vec[start] && k<vec[mid]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }else{
            if(k>vec[mid] && k<=vec[end]){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
    }
    return -1;
}
