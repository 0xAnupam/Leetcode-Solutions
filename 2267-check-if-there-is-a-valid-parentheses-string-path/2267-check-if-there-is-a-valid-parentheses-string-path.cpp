int dp[101][101][201];
bool way(vector<vector<char>>& grid,int i,int j,int m,int n,int s){
        if(i>=m || j>=n){
                return 0;
        }
        if(grid[i][j]=='('){
                s++;
        }
        else{
                s--;
        }
        if(s<0){
                return 0;
        }
        if(i==m-1 && j==n-1){
                return s==0;
        }
        if(dp[i][j][s]!=-1){
                return dp[i][j][s];
        }
        return dp[i][j][s]=way(grid,i+1,j,m,n,s)||way(grid,i,j+1,m,n,s);
}
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
            if(grid[0][0]!='(' || grid[m-1][n-1]!=')'){
                    return 0;
            }
            memset(dp,-1,sizeof(dp));
            return way(grid,0,0,m,n,0);
    }
};