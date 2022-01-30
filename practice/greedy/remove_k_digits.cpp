leetcode

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
	
	
	
	 string removeKdigits(string num, int k) {
        stack<char> st;
        st.push(num[0]);
        // k=k%num.size();
        for(int i=1; i<num.size(); i++){
            while(!st.empty() && k>0 && num[i] < st.top()){
                st.pop();
                k--;
            }
            st.push(num[i]);
            if(st.size() == 1 && num[i] == '0') st.pop();
        }
        string ans = "";
        while(!st.empty()){
            if(k>0) k--;
            else ans+= st.top();    
            st.pop();
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        if(ans == "") return "0";
        return ans;
    }
