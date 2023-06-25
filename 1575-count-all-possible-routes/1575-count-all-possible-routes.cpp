const int N=101;
long long dp[N][N<<1];
const long long mod=1e9+7;
long long f(vector<int>& locations,int st,int en,int fuel,int n){
        if(dp[st][fuel]!=-1){
                return dp[st][fuel];
        }
        long long res=(st==en);
        for(int i=0;i<n;i++){
                if(i!=st && abs(locations[st]-locations[i])<=fuel){
                        res+=f(locations,i,en,fuel-abs(locations[st]-locations[i]),n);
                        if(res>=mod){
                                res%=mod;
                        }
                }
        }
        return dp[st][fuel]=res;
        
}
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
            memset(dp,-1,sizeof(dp));
            return f(locations,start,finish,fuel,n);
    }
};