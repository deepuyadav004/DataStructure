
// The problem is to count all the paths from top left to bottom right of a 
//mXn matrix with the constraints that from each cell you can either moveonly to right or down

// input (3,3)
// output 6


#include <iostream>

using namespace std;

int grid(int n, int m){
    
    
    
    int matrix[n][m];
    for(int i=0; i<n; i++){
        matrix[i][0]=1;
    }
    for(int j=0; j<m; j++){
        matrix[0][j]=1;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            matrix[i][j]=matrix[i-1][j]+matrix[i][j-1];
        }
    }
    return matrix[n-1][m-1];
}

int main()
{
    cout<<grid(3,3)<<endl;

    return 0;
}
