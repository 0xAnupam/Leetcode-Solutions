long long dp[501];
long long f(vector<int>&nums,int idx,int n,int k){
        if(idx==n){
                return 0;
        }
        if(dp[idx]!=-1){
                return dp[idx];
        }
        long long m=nums[idx],res=0;
        int N=min(n,idx+k);
        for(int i=idx;i<N;i++){
                m=max(m,1LL*nums[i]);
                res=max(res,m*(i-idx+1)+f(nums,i+1,n,k));
        }
        return dp[idx]=res;
        
}
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
            memset(dp,-1,sizeof(dp));
        return f(nums,0,nums.size(),k);
    }
};