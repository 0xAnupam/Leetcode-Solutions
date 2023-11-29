const int mod=1e9+7;
class Solution {
public:
    int numWays(string s) {
        int cnt=0;
            for(auto &i:s)cnt+=(i=='1');
            if(cnt%3)return 0;
            if(cnt==0){
                    long long n=s.size();
                    long long res=((n-2)*(n-1))/2;
                    res%=mod;
                    return res;
            }
            int A=0,B=0,a=0,b=0;
            cnt/=3;
            for(auto &i:s){
                    a+=(i=='1');
                    A+=(a==cnt);
            }
            reverse(s.begin(),s.end());
            for(auto &i:s){
                    b+=(i=='1');
                    B+=(b==cnt);
            }
            return (A*1LL*B)%mod;
    }
};