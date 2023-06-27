long long rec(vector<vector<int>>& matrix,vector<vector<long long>> &dp,int r,int c,int n)
        { 
          if(c<0 || r>=n || c>=n)
          {
                  return INT_MAX;
          }
          
          if(dp[r][c]!=1e5)
          {
                  return dp[r][c];
          }
          if(r==n-1)
          {
                  return dp[r][c]=matrix[r][c];
          }
         return dp[r][c]=matrix[r][c]+min({rec(matrix,dp,r+1,c-1,n),rec(matrix,dp,r+1,c,n),rec(matrix,dp,r+1,c+1,n)});
                
        }
class Solution {
public:
  
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
            vector<vector<long long>> dp(n,vector<long long>(n,1e5));
          long long res=INT_MAX;
            for(int i=0;i<n;i++){
                    res=min(res,rec(matrix,dp,0,i,n));
            }
            return res;
    }
};