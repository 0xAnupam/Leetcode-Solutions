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
class Solution {
public:
    int countGoodNumbers(long long n) {
        long long res=mpow(4LL,n/2,mod);
            res%=mod;
            res*=mpow(5LL,(n+1)/2,mod);
            res%=mod;
            return res;
            
    }
};