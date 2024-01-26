class Solution {
public: const long long mod=1e9+7;
        long long dp[51][51][51];
        vector<pair<int,int>> moves={{-1,0},{1,0},{0,-1},{0,1}};
        bool valid(int i,int j,int m,int n){
                return (i>=0 && j>=0 && i<m && j<n);
        }
        long long out(int m,int n,int i,int j,int maxmove){
                if(!valid(i,j,m,n)){
                        return 1;
                }
                if(maxmove==0){
                        return 0;
                }
                if(dp[i][j][maxmove]!=-1){
                        return dp[i][j][maxmove];
                }
                long long res=0;
                for(auto &xy:moves){
                        res+=out(m,n,i+xy.first,j+xy.second,maxmove-1)%mod;
                        res%=mod;
                }
                return dp[i][j][maxmove]=res;
        }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
            memset(dp,-1,sizeof(dp));
        return out(m,n,startRow,startColumn,maxMove);
    }
};