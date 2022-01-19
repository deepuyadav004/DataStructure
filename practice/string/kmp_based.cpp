Given two strings s1 and s2. The task is to check if s2 is a rotated version of the string s1. The characters in the strings are in lowercase.

 

Example 1:

Input:
geeksforgeeks
forgeeksgeeks
Output: 


1
Explanation: s1 is geeksforgeeks, s2 is
forgeeksgeeks. Clearly, s2 is a rotated
version of s1 as s2 can be obtained by
left-rotating s1 by 5 units.
  
  
  
  
  bool isRotation(string a,
                string b)
{
  int n = a.length();
  int m = b.length();
  if (n != m)
    return false;
 
  // create lps[] that
  // will hold the longest
  // prefix suffix values
  // for pattern
  int lps[n];
 
  // length of the previous
  // longest prefix suffix
  int len = 0;
  int i = 1;
   
  // lps[0] is always 0
  lps[0] = 0;
 
  // the loop calculates
  // lps[i] for i = 1 to n-1
  while (i < n)
  {
    if (a[i] == b[len])
    {
      lps[i] = ++len;
      ++i;
    }
    else
    {
      if (len == 0)
      {
        lps[i] = 0;
        ++i;
      }
      else
      {
        len = lps[len - 1];
      }
    }
  }
 
  i = 0;
 
  // Match from that rotating
  // point
  for (int k = lps[n - 1];
           k < m; ++k)
  {
    if (b[k] != a[i++])
      return false;
  }
  return true;
}
