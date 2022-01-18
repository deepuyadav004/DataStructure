Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], 
check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
  
  
  //-----------------------------------------------------------------------------------------------
  
  Intuition:)
After reading the question we get the gist that we have to reach the index were value is 0 by jumping left and right ,so the best intuition we get is recursion. 
    So now let's think of approach ;)

Algorithm :

First let's think of edge case when our starting location and destination are same. well this is the best case scenerio so we just return true.
From the intuition we know we have to jump left and right ,so before jumping we need to check if we have already been there or not .
  Thus to mark the visited locations we mark them as -1
arr[start] should be marked as visited yup, you guessed it correctly , since we start form arr[start] it should be marked as -1 ;]
Now if righside is less then arr.size() then do the rightside recursion or if leftside is > 0 then we have to do leftside recursion .
Kaboom that's it .
Before starting with code let's take a dry run:
image

Code:-

//Comment and Upvote :)

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        //if we have already visited that value , we return false
        if(arr[start]== -1) return false;
        //best case scenerio will be if arr[start] is 0 so we return true
        if(!arr[start]) return true;
        //For leftside and rightside jumps       
        int leftside= start-arr[start] ,rightside = start+arr[start];
        //since we start from arr[start] it should be marked as visited
        arr[start] = -1;
        
        //Now the scenerio were arr[start] != 0 then we need to check if we can either jump to leftside or rightside i.e recursively 
        return rightside = (rightside < arr.size() && canReach(arr,rightside) ) || (leftside>=0 && canReach(arr,leftside) );
    }
};
Time Complexity: O(n) we are visiting an index only once, in worst can we have to visit all the index lets say we have [1, 1, 1, 1, 1, 1, 0] and start is index = 0
Space Complexity: O(1) we are not using any extra space (if we are not counting recursion stack ).
