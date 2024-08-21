const int mod = 1e9 + 7;
int dp[2001][1001];

class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int x = nums.back(), n = nums.size();
        vector<int> arr = nums;
        arr.push_back(x);
        
        for (int i = n - 1; i >= 0; i--) {
            x = min(x, nums[i]);
            nums[i] = x;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= arr[i]; j++) dp[i][j] = 0;
        }
        for (int i = 0; i <= arr[n]; i++) dp[n][i] = 1+i;
        for (int i = n - 1; i >= 0; i--) {
            for (int cur = 0; cur <= nums[i]; cur++) {
                int l = max(arr[i + 1] - arr[i] + cur, cur);
                int r = arr[i + 1];
                dp[i][cur] = dp[i + 1][r];
                if (l > 0) dp[i][cur] = (dp[i][cur] - dp[i + 1][l - 1] + mod) % mod;
            }
            for (int cur = 1; cur <= arr[i]; cur++) {
                dp[i][cur] += dp[i][cur - 1];
                dp[i][cur] %= mod;
            }
        }
        return dp[0][0];
    }
};
