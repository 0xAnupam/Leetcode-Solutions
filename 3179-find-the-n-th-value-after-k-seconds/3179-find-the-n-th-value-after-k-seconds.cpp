const int N=2e3+10;
long long fact[N];
const long long mod=1e9+7;
long long mpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
long long inv(int a,int m){
   return mpow(a,m-2,m);
}
long long ncr(int n,int r){
    if(r==0)return 1;
    long long res=fact[n];
    
    res*=inv(fact[r],mod);
    res%=mod;
    res*=inv(fact[n-r],mod);
    res%=mod;
    return res;
}
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        fact[0]=fact[1]=1;
        for(long long i=2;i<n+k;i++)fact[i]=(i*fact[i-1])%mod;
        return ncr(n+k-1,k);
    }
};