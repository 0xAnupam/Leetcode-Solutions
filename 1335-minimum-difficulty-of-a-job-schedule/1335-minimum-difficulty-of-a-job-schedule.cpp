
long long dp[301][11][1001];
class Solution {
public: 
        long long job(vector<int> &x,int ind,int d,int maxi){
                if(ind==x.size()){
                        if(d==0){return maxi;}
                        return 1e6;
                }
                if(d<0){
                        return 1e6;
                }
                if(dp[ind][d][maxi]!=-1){
                        return dp[ind][d][maxi];
                }
return dp[ind][d][maxi]=min(max(x[ind],maxi)+job(x,ind+1,d-1,0),job(x,ind+1,d,max(x[ind],maxi)));
        }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
            memset(dp,-1,sizeof(dp));
        long long res=job(jobDifficulty,0,d,0);
            if(res>=1e6){
                    return -1;
            }
            return res;
    }
};