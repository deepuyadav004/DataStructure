You are given a string S of alphabet characters and the task is to find its matching decimal representation as on the shown keypad.
  Output the decimal representation corresponding to the string. For ex: if you are given “amazon” then its corresponding decimal representation will be 262966.



Example 1:

Input:
S = geeksforgeeks
Output: 4335736743357
Explanation:geeksforgeeks is 4335736743357
in decimal when we type it using the given
keypad.
  
  
  
  string printNumber(string s, int n) 
{
    //code here
    for(int i=0; i<n; i++){
        if(s[i]>='a' && s[i]<='c'){
            s[i]='2';
        }else if(s[i]>='d' && s[i]<='f'){
            s[i]='3';
        }else if(s[i]>='g' && s[i]<='i'){
            s[i]='4';
        }else if(s[i]>='j' && s[i]<='l'){
            s[i]='5';
        }else if(s[i]>='m' && s[i]<='o'){
            s[i]='6';
        }else if(s[i]>='p' && s[i]<='s'){
            s[i]='7';
        }else if(s[i]>='t' && s[i]<='v'){
            s[i]='8';
        }else if(s[i]>='w' && s[i]<='z'){
            s[i]='9';
        }
        
        
    }
    return s;
}
