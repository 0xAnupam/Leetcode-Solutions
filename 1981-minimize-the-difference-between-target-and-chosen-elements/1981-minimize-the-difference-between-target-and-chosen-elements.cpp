const int N=71;
int8_t dp[N][N*N];
void dfs(vector<vector<int>> &arr,int idx,int n,int m,int sum){
    
    if(dp[idx][sum]){
        return ;
    }
    if(idx==n){
        dp[idx][sum]=1;
        return ;
    }
    for(int i=0;i<m;i++){
        dfs(arr,idx+1,n,m,sum+arr[idx][i]);
    }
    dp[idx][sum]=1;
}
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp,0,sizeof(dp));
        int n=mat.size(),m=mat[0].size();
        dfs(mat,0,n,m,0);
        int res=1e9;
        int k=min(800*n,N*N-1); 
        for(int i=0;i<=k;i++){
            if(dp[n][i]){
                res=min(res,abs(target-i));
            }
        }
            return res;
    }
};