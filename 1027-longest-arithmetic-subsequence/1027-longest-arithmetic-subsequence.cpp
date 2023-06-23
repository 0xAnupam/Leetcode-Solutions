const int N=1e3+1;
int dp[N][N];
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        int res=0;    
        memset(dp,0,sizeof(dp));    
        for(int i=n-1;i>=0;i--){
                for(int j=0;j<i;j++){
                        int diff=nums[i]-nums[j]+500;
                        dp[j][diff]=max(dp[j][diff],1+dp[i][diff]);
                        res=max(res,dp[j][diff]);
                }
        }
            return res+1;
    }
};