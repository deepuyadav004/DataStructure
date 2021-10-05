
// Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference


// Example 1:

// Input: N = 4, arr[] = {1, 6, 11, 5} 
// Output: 1
// Explanation: 
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11   



#include<bits/stdc++.h>
#include<math.h>
#include<time.h>
using namespace std;


// for generatin random number beween 1 to 10
void random_generator(int arr[], int n){
    
    srand(time(0));

    for(int i=0; i<n; i++){
        int temp=rand()%10 + 1;
        arr[i]=temp;
    }
}

// main function
int helper(int arr[], int n){

    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }

    bool dp[n+1][sum+1];

    for(int i=0; i<=n; i++){
        dp[i][0]=true;
    }
    for(int i=1; i<=sum; i++){
        dp[0][i]=false;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            dp[i][j]=dp[i-1][j];

            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j] || dp[i-1][j - arr[i-1]];
            }
        }
    }
    int diff=INT_MAX;
    for(int j=sum/2; j>=0; j--){
        if(dp[n][j]==true){
            diff=sum - 2*j;
            break;
        }
    }
    return diff;
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    random_generator(arr,n);
    cout<<"array was"<<endl;
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<helper(arr,n)<<endl;
    return 0;
}

