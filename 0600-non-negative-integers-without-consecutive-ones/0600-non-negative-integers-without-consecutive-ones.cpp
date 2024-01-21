string Bin(int n){
        string res="";
        while(n){
                int p=n&1;
                res+=('0'+p);
                n>>=1;
        }
        reverse(res.begin(),res.end());
        return res;
}
int dp[31][2][2];
int f(string &s,int idx,int n,bool tight,bool k){
        if(idx==n){
                return 1;
        }
        if(dp[idx][tight][k]!=-1)return dp[idx][tight][k];
        int res=0;
        if(tight){
                res=f(s,idx+1,n,(s[idx] == '0'),1);
                if(k && s[idx]=='1'){
                        res+=f(s,idx+1,n,1,0);
                }
        }
        else{
                res=f(s,idx+1,n,0,1);
                if(k){
                        res+=f(s,idx+1,n,0,0);
                }
        }
        return dp[idx][tight][k]=res;
}
class Solution {
public:
    int findIntegers(int n) {
      string s=Bin(n);
            memset(dp,-1,sizeof(dp));
            return f(s,0,s.size(),1,1);
    }
};