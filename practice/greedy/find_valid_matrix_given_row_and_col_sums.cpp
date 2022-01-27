leetcode


You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is the sum of the elements in the ith row and colSum[j] is the sum of the elements of the 
jth column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.

Find any matrix of non-negative integers of size rowSum.length x colSum.length that satisfies the rowSum and colSum requirements.

Return a 2D array representing any matrix that fulfills the requirements. It's guaranteed that at least one matrix that fulfills the requirements exists.
  
  
  
   vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        int m=rowSum.size();
        int n=colSum.size();
        vector<vector<int>>ans(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            if(rowSum[i]==0){
                continue;
            }
            
            for(int j=0; j<n; j++){
                if(colSum[j]==0){
                    continue;
                }
                
                ans[i][j]=min(rowSum[i], colSum[j]);
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
            }
        }
        return ans;
    }
