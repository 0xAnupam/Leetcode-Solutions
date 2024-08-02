int fun(vector<int>& nums , int index  , int n , vector<int> &dp){
    if(index==n)return 0;
    if(dp[index]!=INT_MIN)return dp[index];
    int res=fun(nums,index+1,n,dp);
    return dp[index]=nums[index]+max(0,res);
}
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int res=INT_MIN;
        vector<int> dp(n,INT_MIN);
        for(int i=0;i<n;i++)res=max(res,fun(nums,i,n , dp));
        return res;
    }
};