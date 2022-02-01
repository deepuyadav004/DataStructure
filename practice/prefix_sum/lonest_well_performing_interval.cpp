leetcode

We are given hours, a list of the number of hours worked per day for a given employee.

A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.

Return the length of the longest well-performing interval.

 

Example 1:

Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].
Example 2:

Input: hours = [6,6,6]
Output: 0




// Note : Similiar to question in which we have to find longest subarray with more ones than zeroes
class Solution {
public:
	int longestWPI(vector<int>& hours) {
		 int sum=0,ans=0;
		//sum to index mapping
		 unordered_map<int,int> mp;
		 for(int i=0;i<hours.size();i++){
			 sum+=hours[i]>8?1:-1;
			 //if sum till index i is greater than 0 means we have more 1(tiring days) than 
			 //non-tiring days(-1)
			 if(sum>0)   ans=max(ans,i+1);
			 else if(mp.find(sum)==mp.end()) mp[sum]=i;

			 if(mp.find(sum-1)!=mp.end())  ans=max(ans,i-mp[sum-1]);   
		 }
		return ans;
	}
};
