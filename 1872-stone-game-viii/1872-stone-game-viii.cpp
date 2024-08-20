long long dp[(int)1e5+1];
long long f(vector<int> &stones,int idx,int n){
    if(idx==n)return INT_MAX;
    if(idx==n-1)return stones[idx];
    if(dp[idx]!=LLONG_MAX)return dp[idx];
    return dp[idx]=max(f(stones,idx+1,n),stones[idx]-f(stones,idx+1,n));
}
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int s=0;
        for(auto &i:stones)s+=i,i=s;
        int n=stones.size();
        for(int i=0;i<n;i++)dp[i]=LLONG_MAX;
        return f(stones,1,n);
    }
};