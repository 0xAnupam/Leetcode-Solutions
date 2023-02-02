int dp[100001];
bool f(vector<int>&nums,int idx,int n){
        
        if(idx==n){
                return 1;
        }
        if(idx>n){
                return 0;
        }
        if(idx==n-1){
                return 0;
        }
        if(dp[idx]!=-1){
                return dp[idx];
        }
        bool flag=(nums[idx]==nums[idx+1]);
        
        if(flag && f(nums,idx+2,n)){
                return dp[idx]=flag;
        }
        if(idx==n-2){
                return dp[idx]=0;
        }
        if(flag && nums[idx+2]==nums[idx]){
                return dp[idx]=f(nums,idx+3,n);
        }
        if(nums[idx]+1==nums[idx+1] && nums[idx+1]+1==nums[idx+2]){
                return dp[idx]=f(nums,idx+3,n);
        }
        return dp[idx]=0;
}
class Solution {
public:
    bool validPartition(vector<int>& nums) {
            memset(dp,-1,sizeof(dp));
        return f(nums,0,nums.size());
    }
};