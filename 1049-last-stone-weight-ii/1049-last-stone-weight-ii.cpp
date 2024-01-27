void f(vector<int> &arr,int idx,int n,int &res,int sum,vector<vector<int>> &dp,int g){
        if(idx==n){
                res=min(res,abs(sum-g));
                return ;
        }
        if(dp[idx][sum]++)return ;
        f(arr,idx+1,n,res,sum+arr[idx],dp,g);
        f(arr,idx+1,n,res,sum-arr[idx],dp,g);
}
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
            int n=stones.size(),origin=0;
            for(auto &i:stones){
                    origin+=i;
            }
            int N=2*origin+1;
            vector<vector<int>> dp(n,vector<int>(N,0));
            int res=1e9;
            f(stones,0,n,res,origin,dp,origin);
        
            return res;
    }
};