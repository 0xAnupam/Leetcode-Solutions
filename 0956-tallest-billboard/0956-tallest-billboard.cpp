int dp[2501][2501];
int f(vector<int> &rods,int a,int b,int idx,int n,int s){
        if(max(a,b)-min(a,b)>s){
                return 0;
        }
        if(idx==n){
                if(a==b){
                        return a;
                }
                return 0;
        }
        if(dp[max(a,b)][min(a,b)]!=-1){
                return dp[max(a,b)][min(a,b)];
        }
        if(a==b){
              return dp[a][b]=max(f(rods,a,b+rods[idx],idx+1,n,s-rods[idx]),f(rods,a,b,idx+1,n,s-rods[idx]));
        }
        return dp[max(a,b)][min(a,b)]=max({f(rods,a+rods[idx],b,idx+1,n,s-rods[idx]),f(rods,a,b+rods[idx],idx+1,n,s-rods[idx]),f(rods,a,b,idx+1,n,s-rods[idx])});
}
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
            memset(dp,-1,sizeof(dp));
            sort(rods.rbegin(),rods.rend());
            int s=0,n=rods.size();
            for(auto &i:rods){
                    s+=i;
            }
           
        return f(rods,0,0,0,rods.size(),s);
    }
};