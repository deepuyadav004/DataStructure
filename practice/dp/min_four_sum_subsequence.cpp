Given an array A[] of positive integers. The task is to complete the function which returns an integer denoting the minimum sum subsequence from the array such that at least one value among all groups of four consecutive elements is picked.
Examples:

Input: A[] = {1, 2, 3, 4, 5, 6, 7, 8}
Output: 6
6 is sum of output subsequence {1, 5}
Following 4 length subarrays are possible
(1, 2, 3, 4), (2, 3, 4, 5), (3, 4, 5, 6),
(4, 5, 6, 7), (5, 6, 7, 8)
Here, Our subsequence {1, 5} has an element from all
above groups of four consecutive elements.
  
  
  
  int minSum(int arr[], int n)
{
    // dp[i] is going to store minimum sum
    // subsequence of arr[0..i] such that arr[i]
    // is part of the solution. Note that this
    // may not be the best solution for subarray
    // arr[0..i]
    int dp[n];

    // If there is single value, we get the
    // minimum sum equal to arr[0]
    if (n == 1)
        return arr[0];

    // If there are two values, we get the
    // minimum sum equal to the minimum of
    // two values
    if (n == 2)
        return min(arr[0], arr[1]);

    // If there are three values, return
    // minimum of the three elements of
    // array
    if (n == 3)
        return min(arr[0], min(arr[1], arr[2]));

    // If there are four values, return minimum
    // of the four elements of array
    if (n == 4)
        return min(min(arr[0], arr[1]),
                   min(arr[2], arr[3]));

    dp[0] = arr[0];
    dp[1] = arr[1];
    dp[2] = arr[2];
    dp[3] = arr[3];

    for (int i = 4; i < n; i++)
        dp[i] = arr[i] + min(min(dp[i - 1], dp[i - 2]),
                             min(dp[i - 3], dp[i - 4]));

    // Return the minimum of last 4 index
    return min(min(dp[n - 1], dp[n - 2]),
               min(dp[n - 4], dp[n - 3]));
}
