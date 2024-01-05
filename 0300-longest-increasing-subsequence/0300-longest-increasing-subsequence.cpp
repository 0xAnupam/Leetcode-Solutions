class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),res=1;
            int dp[n];
            dp[n-1]=1;
            for(int i=n-2;i>=0;i--){
                    dp[i]=1;
                    for(int j=i+1;j<n;j++){
                            if(nums[j]>nums[i])dp[i]=max(dp[i],1+dp[j]);
                    }
                    res=max(res,dp[i]);
            }
            return res;
    }
};