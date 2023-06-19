const long long mod=1e9+7;
long long dp[40][1<<10];
class Solution {
public: 
        long long ways(vector<vector<int>> &hats,int i,long long j){
                if(j==0){
                        return 1;
                }
                if(i==40){
                        return 0;
                }
                if(dp[i][j]!=-1){
                        return dp[i][j];
                }
                long long res=ways(hats,i+1,j);
                for(int k=0;k<hats.size();k++){
                        if((1<<k)&j){
                                for(auto &ele:hats[k]){
                                        if(ele==i){
                                                res+=ways(hats,i+1,(j^(1<<k)));
                                                res%=mod;
                                        }
                                }
                        }
                }
                return dp[i][j]=res;
        }
    int numberWays(vector<vector<int>>& hats) {
            memset(dp,-1,sizeof(dp));
             for(auto &i:hats){
                     for(auto &j:i){
                             j--;
                     }
             }
            int n=hats.size();
        return ways(hats,0,(1<<n)-1);
            
    }
};