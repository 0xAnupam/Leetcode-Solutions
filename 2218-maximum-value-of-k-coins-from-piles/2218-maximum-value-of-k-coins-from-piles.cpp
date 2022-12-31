long long dp[1001][2001];
long long f(vector<vector<int>>&piles,int idx,int n,int k,vector<int> &opt){
        if(n==idx || k==0 || opt[idx]<k){
                return 0;
        }
        if(dp[idx][k]!=-1){
                return dp[idx][k];
        }
        int m=piles[idx].size();
        long long res=f(piles,idx+1,n,k,opt),sum=0;
        for(int i=0;i<min(m,k);i++){
                sum+=piles[idx][i];
                res=max(res,sum+f(piles,idx+1,n,k-i-1,opt));
        }
        //cout<<idx<<" "<<res<<'\n';
        return dp[idx][k]=res;
        
}
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
            memset(dp,-1,sizeof(dp));
            
            int sum=0;
            
        int n=piles.size(),m=piles[0].size();
            vector<int> opt(n);
            for(int i=n-1;i>=0;i--){
                    sum+=piles[i].size();
                    opt[i]=sum;
            }
            return f(piles,0,n,k,opt);
    }
};