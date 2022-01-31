Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
  
  
  
   int findMaxLength(vector<int>& nums) {
        
        map<int, int>mp;
        mp[0]=-1;
        int maxlen=0, count=0;
        for(int i=0; i<nums.size(); i++){
            count=count+(nums[i]==1?1:-1);
            if(mp.find(count) != mp.end()){
                maxlen=max(maxlen, i-mp[count]);
            }else{
                mp[count]=i;
            }
        }
        return maxlen;
    }
