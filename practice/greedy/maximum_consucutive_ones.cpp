leetcode

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined



 int longestOnes(vector<int>& nums, int k) {
        
        queue<int>q;
        int count=0;
        int res=0;
        int start=-1;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                q.push(i);
                if(count<k){
                    count++;
                }else if(count==k){
                    start=q.front();
                    q.pop();
                    
                }
            }
            res=max(res, i-start);
        }
        return res;
    }
    

// sliding window


int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int res=0;
        int n=nums.size();
        int cnt=0;
        while(r<n){
            if(nums[r]==0){
                cnt++;
            }
            
            
            while(cnt>k){
                if(nums[l]==0){
                    cnt--;
                }
                
                l++;
            }
            
            
            res=max(res,r-l+1);
            r++;
        }
        
        return res;
    }
