// Approach 4: Expand Around Center
// In fact, we could solve it in O(n^2)O(n 
// 2
//  ) time using only constant space.

// We observe that a palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only 2n - 12n−1 such centers.

// You might be asking why there are 2n - 12n−1 but not nn centers? The reason is the center of a palindrome can be in between two letters. Such palindromes have even number of letters (such as "abba") and its center are between the two 'b's.


string longestPalindrome(string s) {
        
        if(s.length() < 1){
            return "";
        }
        int start =0;
        int end =0;
        for(int i=0; i<s.length(); i++){
            int len1=expand(s, i, i);
            int len2=expand(s, i, i+1);
            int len=max(len1, len2);
            if(len > end-start){
                start = i-(len-1)/2;
                end=i+len/2;
            }
        }
        return s.substr(start, end-start+1);
        
    }
    
    int expand(string s, int left, int right){
        int i=left, j=right;
        while(i >= 0 && j<s.length() && s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }
};
