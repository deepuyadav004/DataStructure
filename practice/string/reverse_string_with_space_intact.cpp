Given a string, your task is to reverse the string keeping the spaces intact to their positions.

Example 1:

Input:
S = "Help others"
Output: sreh topleH
Explanation: The space is intact at index 4
while all other characters are reversed.
  
   string reverseWithSpacesIntact (string s)
        {
            //code here.
            int low=0;
            int high=s.length()-1;
            while(low < high){
                if(s[low]==' '){
                    low++;
                }else if(s[high]==' '){
                    high--;
                }else if(s[low] != ' ' && s[high] != ' '){
                    swap(s[low], s[high]);
                    low++;
                    high--;
                }
            }
            return s;
        }
