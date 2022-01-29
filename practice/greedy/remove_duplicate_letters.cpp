Leetcode

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
	
	
 string removeDuplicateLetters(string s) {
        
        unordered_map<char, int>mp;
        vector<bool>v(1000,false);
        for(int i=0; i<s.length(); i++){
            mp[s[i]]=i;
        }
        string ans="";
        for(int i=0; i<s.length(); i++){
            
           if(v[s[i]-'a']){
               continue;
           }
            
            while(!ans.empty() and ans.back()>s[i] and mp[ans.back()]>i){
                v[ans.back()-'a']=false;
                ans.pop_back();
            }
            
            ans+=s[i];
            v[s[i]-'a']=true;
        }
        return ans;
    }

