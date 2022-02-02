Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.
  
  
  intution :- if we find sum in set this means there was a range of number which increases and decreases the value of sum by same amount that's why sum is same as any previous state and found in set.
    
    
     bool subArrayExists(int arr[], int n)
    {
        //Your code here
        set<int>s;
        s.insert(0);
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(s.find(sum) != s.end()){
                return true;
            }
            s.insert(sum);
        }
        return false;
    }
