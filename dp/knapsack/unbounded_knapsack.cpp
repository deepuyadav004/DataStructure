// Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
// The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
// Note: Each item can be taken any number of times.

 

// Example 1:

// Input: N = 2, W = 3
// val[] = {1, 1}
// wt[] = {2, 1}
// Output: 3
// Explanation: 
// 1.Pick the 2nd element thrice.
// 2.Total profit = 1 + 1 + 1 = 3. Also the total 
//   weight = 1 + 1 + 1  = 3 which is <= W.



#include<bits/stdc++.h>
using namespace std;

int unbounded_knapsack(int n, int w, int val[], int wt[]){

  int matrix[n+1][w+1];
  for(int i=0; i<=n; i++){
    matrix[i][0]=0;
  }
  for(int j=0; j<=w; j++){
    matrix[0][j]=0;
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=w; j++){
      if(wt[i-1] <= j){
        matrix[i][j]=max(val[i-1]+matrix[i][j-wt[i-1]], matrix[i-1][j]);
      }else{
        matrix[i][j]=matrix[i-1][j];
      }
    }
  }
  return matrix[n][w];
}

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n,w;
  cin>>n>>w;
  int val[n];
  for(int i=0; i<n; i++){
    cin>>val[i];
  }
  int wt[n];
  for(int j=0; j<n; j++){
    cin>>wt[j];
  }
  cout<<unbounded_knapsack(n,w,val,wt)<<endl;
  return 0;
}
