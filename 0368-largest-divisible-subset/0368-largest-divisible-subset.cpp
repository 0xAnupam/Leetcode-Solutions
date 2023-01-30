vector<int> lis(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> pre(n, -1);
    int len = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] ==0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                pre[i] = j;
                if (dp[i] > len) {
                    len = dp[i];
                    idx = i;
                }
            }
        }
    }

    vector<int> lis;
    while (idx != -1) {
        lis.push_back(nums[idx]);
        idx = pre[idx];
    }
    reverse(lis.begin(), lis.end());
    return lis;
}
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
            return lis(nums);
    }
};