const long long m=1e9+7;
long long f(vector<int>& nums, long long k)
{
    long long n = nums.size();
    long long dp[n + 1][k + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (long long i = 1; i <= n; i++)
        for (long long j = 0; j < k; j++){
            dp[i][j] = (dp[i - 1][j]%m + (j >= nums[i - 1] ? dp[i - 1][j - nums[i - 1]] : 0)%m)%m;
        }
            
    long long result = 0;
    for (long long j = 0; j < k; j++)
        result += dp[n][j]%m;
        result%=m;

    return result;
}
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
    int countPartitions(vector<int>& nums, int k) {
            long long s=0;
            for(auto &i:nums){
                    s+=i;
            }
            if(s<2*k){
                    return 0;
            }
       
            long long res=(mpow(2LL,(int)nums.size(),m)+m-2*f(nums,k))%m;
            return res;
    }
};