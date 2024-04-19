const int N=1e4+1;
unordered_map<int,int> dp[N][10];
int f(vector<int> &nums,int idx,int n,vector<int>& andValues,int j,int m,int cur){
        if(idx==n && j==m)return 0;
        if(idx==n || j==m)return 1e9;
        if((cur&andValues[j])!=andValues[j])return 1e9;
        if(dp[idx][j].count(cur))return dp[idx][j][cur];
        if((nums[idx]&cur)==andValues[j]){
                return dp[idx][j][cur]=min(f(nums,idx+1,n,andValues,j,m,(nums[idx]&cur)),nums[idx]+f(nums,idx+1,n,andValues,j+1,m,-1));
        }
        return dp[idx][j][cur]=f(nums,idx+1,n,andValues,j,m,(nums[idx]&cur));
}
class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n=nums.size(),m=andValues.size();
            for(int i=0;i<n;i++)for(int j=0;j<m;j++)dp[i][j].clear();
            return f(nums,0,n,andValues,0,m,-1)==(int)1e9 ? -1 : dp[0][0][-1];
    }
};