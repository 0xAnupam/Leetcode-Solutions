class Solution{
    public: 
        int fun(vector<int> &nums, int ind, vector<int> &dp){
                if (ind >= nums.size()){
                    return 0;
                }
                if (dp[ind] != -1){
                    return dp[ind];
                }
        return dp[ind] = max(nums[ind] + fun(nums, ind + 2, dp), fun(nums, ind + 1, dp));
    }
    int rob(vector<int> &nums){
        vector<int> dp(nums.size(), -1);
        return fun(nums, 0, dp);
    }
};