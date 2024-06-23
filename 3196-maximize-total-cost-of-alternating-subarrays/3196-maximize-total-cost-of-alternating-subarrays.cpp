long long dp[100001];
const long long INF=1e18;
long long f(vector<int>& nums,int idx,int n ){
    if(idx==n)return 0;
    if(idx==n-1)return nums[idx];
    if(dp[idx]!=INF)return dp[idx];
    return dp[idx]= nums[idx]+max(f(nums,idx+2,n)-nums[idx+1],f(nums,idx+1,n));
}
class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)dp[i]=INF;
        return f(nums,0,n);
    }
};