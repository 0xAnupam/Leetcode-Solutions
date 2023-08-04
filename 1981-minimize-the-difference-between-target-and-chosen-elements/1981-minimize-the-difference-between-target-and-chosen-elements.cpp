const int N=70;
int8_t dp[N+1][N*N*N+1];
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
        for(auto &i:mat){
                sort(i.begin(),i.end());
        }
        sort(mat.begin(),mat.end());
        dfs(mat,0,n,m,0);
        int res=1e9;
        for(int i=0;i<800*n+1;i++){
            if(dp[n][i]){
                res=min(res,abs(target-i));
            }
        }
            return res;
    }
};