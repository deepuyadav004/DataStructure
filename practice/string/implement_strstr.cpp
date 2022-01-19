Your task is to implement the function strstr. The function takes two strings as arguments (s,x) and  locates the occurrence of the string x in the string s.
  The function returns and integer denoting the first occurrence of the string x in s (0 based indexing).

Note: You are not allowed to use inbuilt function.

 

Example 1:

Input:
s = GeeksForGeeks, x = Fr
Output: -1
Explanation: Fr is not present in the
string GeeksForGeeks as substring.
  
  int strstr(string s, string x)
{
     //Your code here
     int c=-1;
     for(int i=0; i<s.length(); i++){
         char ch=s[i];
         string st;
         if(ch==x[0]){
             st=s.substr(i, x.length());
         }
         if(st==x){
             c=i;
             break;
         }
     }
     return c;
}
