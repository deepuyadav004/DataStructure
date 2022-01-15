You are given an array arr[] of size N.
The array consists of a permutation of the set {1, 2, 3, … , N} for some positive integer N. You have to start at the position which has 1 in the array and then travel to the
position which has 2. Then from 2, you travel to 3 and so on till you reach the position which has N.
When you travel from Arr[i] to Arr[j], the distance travelled is | i– j |.
Find the total distance you have to travel to reach N when you start from 1.


Example 1:

Input:
N = 5
Arr[] = {5, 1, 4, 3, 2}
Output: 7
Explanation: The numbers and their respective 
indices are given below:
1->1
2->4
3->3
4->2
5->0
Total distance =|4-1|+|3-4|+|2-3|+|0-2| 
= 3+1+1+2 = 7.
  
  
  long long distance(int arr[], int n) {
        // code here
        long long ans=0;
        int a[n];
        for(int i=0; i<n; i++){
            a[arr[i]-1]=i;
        }
        for(int i=0; i<n-1; i++){
            ans += abs(a[i]-a[i+1]);
        }
        //  ans += abs(a[n-1]- a[n-2]);
         return ans;
    }
