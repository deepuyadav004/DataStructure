Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.

The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, you are the last one remaining and survive.

Example 1:

Input:
n = 3 k = 2
Output: 3
Explanation: There are 3 persons so 
skipping 1 person i.e 1st person 2nd 
person will be killed. Thus the safe 
position is 3.
  
  
  // explanation 
  
  There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. 
  In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as 
  the executed people are removed), until only the last person remains, who is given freedom. Given the total number of persons n and a number k which indicates that k-1 
  persons are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.
For example, if n = 5 and k = 2, then the safe position is 3. Firstly, the person at position 2 is killed, then person at position 4 is killed, then person at position 1 is 
killed. Finally, the person at position 5 is killed. So the person at position 3 survives. 
If n = 7 and k = 3, then the safe position is 4. The persons at positions 3, 6, 2, 7, 5, 1 are killed in order, and person at position 4 survives.

  
  After the first person (kth from beginning) is killed, n-1 persons are left. So we call josephus(n - 1, k) to get the position with n-1 persons. But the position returned 
  by josephus(n - 1, k) will consider the position starting from k%n + 1. So, we must make adjustments to the position returned by josephus(n - 1, k). 

#Another Approach using List:

The simple approach is to create a list and add all values from 1 to n in it. Create a recursive function that takes list, start (position at which counting will start) and 
  k ( number of person to be skipped) as argument. If size of list is one i.e. only one person left then return this position. Otherwise, start counting k person in clockwise 
  direction from starting position and remove the person at kth position. Now the person at kth position is removed and now counting will start from this position. This process
  continues till only one person left.


  
  
   //-----------------------------------------------------------------------------------------------------------------------------------------------------------
  
   vector<int>temp;
    public:
    int helper(int start, int k, int n){
        if(temp.size()==1){
            return temp[0];
        }
        start=(start+k)%n;
        temp.erase(temp.begin()+start);
        n=temp.size();
        return helper(start, k, n);
    }
    
    int josephus(int n, int k)
    {
       //Your code here
       for(int i=1; i<=n; i++){
           temp.push_back(i);
       }
       
       return helper(0,k-1,n);
    }
