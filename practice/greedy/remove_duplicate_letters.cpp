Leetcode

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
	
	
	 string removeDuplicateLetters(string s) {
        
        unordered_map<char, int>last;
        vector<bool>vis(26,true);
        
        for(int i=0; i<s.length(); i++){
            last[s[i]]=i;
            vis[i]=s[i]-'a';
            
        }
        string ans="";
        for(int i=0; i<s.length(); i++){
            
            while(!ans.empty() && ans.back()>s[i] && last[s[i]]>i){
                ans+=s[i];
                vis[s[i]-'a']=false;
            }
            
            ans+=s[i];
            vis[s[i]-'a']=false;
        }
        return s;
    }
