const int N=1e4+1;
int arr[N];
int dp[N];
int f(int idx){
        if(idx>=N){
                return 0;
        }
        if(dp[idx]!=-1){
                return dp[idx];
        }
        int take=idx*arr[idx]+f(idx+2);
        int not_take=f(idx+1);
        return dp[idx]=max(take,not_take);
}
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        memset(arr,0,sizeof(arr));
        memset(dp,-1,sizeof(dp));
            for(auto &i:nums){
                    arr[i]++;
            }
            return f(0);
    }
};