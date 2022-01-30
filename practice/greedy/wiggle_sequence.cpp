leetcode

A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.

 

Example 1:

Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).
Example 2:

Input: nums = [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length.
One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).
  

  We need not necessarily need dp to solve this problem. This problem is equivalent to finding the number of alternating max. and min. peaks in the array. Since, if we choose any other intermediate number to be a part of the current wiggle subsequence, the maximum length of that wiggle subsequence will always be less than or equal to the one obtained by choosing only the consecutive max. and min. elements.

This can be clarified by looking at the following figure: Wiggle Peaks

From the above figure, we can see that if we choose C instead of D as the 2nd point in the wiggle subsequence, we can't include the point E. Thus, we won't obtain the maximum length wiggle subsequence.

Thus, to solve this problem, we maintain a variable \text{prevdiff}prevdiff, where \text{prevdiff}prevdiff is used to indicate whether the current subsequence of numbers lies in an increasing or decreasing wiggle. If \text{prevdiff} > 0prevdiff>0, it indicates that we have found the increasing wiggle and are looking for a decreasing wiggle now. Thus, we update the length of the found subsequence when \text{diff}diff (nums[i]-nums[i-1]nums[i]−nums[i−1]) becomes negative. Similarly, if \text{prevdiff} < 0prevdiff<0, we will update the count when \text{diff}diff (nums[i]-nums[i-1]nums[i]−nums[i−1]) becomes positive.
  
  
  
  
   int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2){
            return nums.size();
        }
        int prevdiff=nums[1]-nums[0];
        int count = prevdiff==0?1:2;
        for(int i=2; i<nums.size(); i++){
            int diff=nums[i]-nums[i-1];
            if((diff>0 && prevdiff<=0) || (diff<0 && prevdiff>=0)){
                count++;
                prevdiff=diff;
            }
        }
        return count;
    }
