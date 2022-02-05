Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

 

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
  
  
  //------------------------------------------------------------ divide and conquer approach -----------------------------------------------------------------------------
  
  We could apply this strategy by recursively splitting the string into substrings and combine the result to find the longest substring that satisfies the given condition. The longest substring for a string starting at index start and ending at index end can be given by,

longestSustring(start, end) = max(longestSubstring(start, mid), longestSubstring(mid+1, end))
Finding the split position (mid)

The string would be split only when we find an invalid character. An invalid character is the one with a frequency of less than k. As we know, the invalid character cannot be part of the result, we split the string at the index where we find the invalid character, recursively check for each split, and combine the result.

Algorithm

Build the countMap with the frequency of each character in the string s.
Find the position for mid index by iterating over the string. The mid index would be the first invalid character in the string.
Split the string into 2 substrings at the mid index and recursively find the result.
To make it more efficient, we ignore all the invalid characters after the mid index as well, thereby reducing the number of recursive calls.
  
  
  class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.length();
        return helper(s,0,n,k);
    }
    
    int helper(string s, int start, int end, int k){
        
        if(end<k){
            return 0;
        }
        int countMap[26]={0};
        for(int i=start; i<end; i++){
            countMap[s[i]-'a']++;
        }
        
        for(int i=start; i<end; i++){
            if(countMap[s[i]-'a']>=k) continue;
            int mid=i+1;
            while(mid<end && countMap[s[mid]-'a']<k) mid++;
            
            return max(helper(s,start,i,k), helper(s,mid,end,k));
        }
        
        return (end-start);
    }
};



//------------------------------------------------------------------ sliding window -----------------------------------------------------------------------------------

Algorithm

Find the number of unique characters in the string s and store the count in variable maxUnique. For s = aabcbacad, the unique characters are a,b,c,d and maxUnique = 4.

Iterate over the string s with the value of currUnique ranging from 1 to maxUnique. In each iteration, currUnique is the maximum number of unique characters that must be present in the sliding window.

The sliding window starts at index windowStart and ends at index windowEnd and slides over string s until windowEnd reaches the end of string s. At any given point, we shrink or expand the window to ensure that the number of unique characters is not greater than currUnique.

If the number of unique character in the sliding window is less than or equal to currUnique, expand the window from the right by adding a character to the end of the window given by windowEnd

Otherwise, shrink the window from the left by removing a character from the start of the window given by windowStart.

Keep track of the number of unique characters in the current sliding window having at least k frequency given by countAtLeastK. Update the result if all the characters in the window have at least k frequency.
  
  
  class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int countMap[26];
        int maxUnique=helper(s);
        int result=0;
        for(int currUnique=1; currUnique<=maxUnique; currUnique++){
            memset(countMap, 0, sizeof(countMap));
            int windowStart=0, windowEnd=0, idx=0, unique=0, countAtLeastK=0;
            while(windowEnd < s.size()){
                if(unique <= currUnique){
                    idx=s[windowEnd]-'a';
                    if(countMap[idx]==0) unique++;
                    countMap[idx]++;
                    if(countMap[idx]==k) countAtLeastK++;
                    windowEnd++;
                }else{
                    idx=s[windowStart]-'a';
                    if(countMap[idx]==k) countAtLeastK--;
                    countMap[idx]--;
                    if(countMap[idx]==0) unique--;
                    windowStart++;
                }
                if(unique==currUnique && unique==countAtLeastK){
                    result=max(windowEnd-windowStart, result);
                }
            }
        }
        return result;
    }
    
    int helper(string s){
        bool map[26]={0};
        int maxUnique=0;
        for(int i=0; i<s.length(); i++){
            if(!map[s[i]-'a']){
                maxUnique++;
                map[s[i]-'a']=true;
            }
        }
        return maxUnique;
    }
};
