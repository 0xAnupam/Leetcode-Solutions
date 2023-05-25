const int N=1e5+1;
const long long mod=1e9+7;
long long dp[N][2];
long long f(string &s,int idx,int n,char c){
        if(idx==n){
                return 0;
        }
        if(dp[idx][c-'0']!=-1){
                return dp[idx][c-'0'];
        }
        if(s[idx]==c){
                return dp[idx][c-'0']=(1+f(s,idx+1,n,'0')+f(s,idx+1,n,'1'))%mod;
        }
        return dp[idx][c-'0']=f(s,idx+1,n,c);
}
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        bool A=0;
        for(auto &i:binary){
                A|=(i=='0');
        }
            int n=binary.size();
        for(int i=0;i<n;i++){
                
                if(binary[i]=='1'){
                        memset(dp,-1,sizeof(dp));
                        return A+f(binary,i,n,'1');
                }
        }
            return A;
    }
};