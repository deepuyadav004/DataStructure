Given two strings A and B. Find the characters that are not common in the two strings. 

Example 1:

Input:
A = geeksforgeeks
B = geeksquiz
Output: fioqruz
Explanation: 
The characters 'f', 'i', 'o', 'q', 'r', 'u','z' 
are either present in A or B, but not in both.
  
  
  
    string UncommonChars(string A, string B)
        {
            // code here
            int a[26]={0};
            int b[26]={0};
            for(int i=0; i<A.length(); i++){
                a[A[i]-'a']=1;
            }
            for(int i=0; i<B.length(); i++){
                b[B[i]-'a']=1;
            }
            string s="";
            for(int i=0; i<26; i++){
                if((a[i]==1 && b[i]==0) || (a[i]==0 && b[i]==1)){
                    s+=char(i+'a');
                }
            }
            if(s.size()==0){
                return "-1";
            }
            return s;
        }
