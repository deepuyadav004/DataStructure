A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.

 

Example 1:

Input: s = "YazaAay"
Output: "aAa"
Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.
  
  
  
  //------------------------------------------------------------------ using recursiion ----------------------------------------------------------------------------------
  
   string longestNiceSubstring(string s) {
        
        if(s.length() < 2){
            return "";
        }
        unordered_set<char>st(s.begin(), s.end());
        
        for(int i=0; i<s.length(); i++){
            if(st.count((char)toupper(s[i]))==false || st.count((char)tolower(s[i]))==false){
                string one=longestNiceSubstring(s.substr(0,i));
                string two=longestNiceSubstring(s.substr(i+1));
                
                return one.length()>=two.length() ? one:two;
            }
        }
        return s;
    }
