class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
            for(int i=0;i<n;i++){
                    dp[0][i]=grid[0][i];
            }
            for(int i=0;i<m-1;i++){
                    for(int j=0;j<n;j++){
                            for(int k=0;k<n;k++){
                            dp[i+1][k]=min(dp[i+1][k],grid[i+1][k]+dp[i][j]+moveCost[grid[i][j]][k]);
                        }
                    }
            }
            return *min_element(dp[m-1].begin(),dp[m-1].end());
    }
};