const int N=1e5+1;
long long dp[N][2];
long long f(vector<int> &nums,int idx,int k,int n){
        if(idx==n){
                return 0;
        }
        if(dp[idx][k]!=-1){
                return dp[idx][k];
        }
        if(k){
                return dp[idx][k]= max(-nums[idx]+f(nums,idx+1,0,n),f(nums,idx+1,1,n));
        }
        return dp[idx][k]=max(nums[idx]+f(nums,idx+1,1,n),f(nums,idx+1,0,n));
}
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
            return f(nums,0,0,nums.size());
    }
};