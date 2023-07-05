class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
            int dp[n][2];
            for(int i=0;i<n;i++){
                    dp[i][0]=dp[i][1]=nums[i];
            }
            int res=nums[0];
            for(int i=1;i<n;i++){
                    dp[i][0]=min(nums[i],min(dp[i-1][0]*nums[i],dp[i-1][1]*nums[i]));
                    dp[i][1]=max(nums[i],max(dp[i-1][1]*nums[i],dp[i-1][0]*nums[i]));
                    res=max(res,max(dp[i][1],dp[i][0]));
            }
            return res;
            
    }
};