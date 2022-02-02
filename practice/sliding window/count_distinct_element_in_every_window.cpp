Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Example 1:

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.
  
  
  Algorithm: 
Create an empty hash map. Let the hash map be hM.
Initialize the count of distinct elements as dist_count to 0.
Traverse through the first window and insert elements of the first window to hM. The elements are used as key and their counts as the value in hM. Also, keep updating dist_count
Print distinct count for the first window.
Traverse through the remaining array (or other windows).
Remove the first element of the previous window. 
If the removed element appeared only once, remove it from hM and decrease the distinct count, i.e. do "dist_count--"
else (appeared multiple times in hM), then decrement its count in hM
Add the current element (last element of the new window) 
If the added element is not present in hM, add it to hM and increase the distinct count, i.e. do "dist_count++"
Else (the added element appeared multiple times), increment its count in hM



vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int>ans;
        unordered_map<int, int>hm;
        int count=0;
        for(int i=0; i<k; i++){
            if(hm[A[i]]==0){
                count++;
            }
            hm[A[i]]+=1;
        }
        
        ans.push_back(count);
        for(int i=k; i<n; i++){
            if(hm[A[i-k]]==1){
                count--;
            }
            hm[A[i-k]]-=1;
            if(hm[A[i]]==0){
                count++;
            }
            hm[A[i]]+=1;
            ans.push_back(count);
        }
        return ans;
    }
