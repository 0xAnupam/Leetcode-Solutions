const int N=1e5+1;
long long dp[N];
long long f(vector<int> &arr,int idx,int n,int diff,map<int,vector<int>> &mp){
        //cout<<idx<<'\n';
        if(idx>=n){
                return 0;
        }
        long long res=1;
        if(dp[idx]!=-1){
                return dp[idx];
        }
        if(mp.find(arr[idx]+diff)==mp.end()){
                return dp[idx]=res;
        }
        auto nums=mp[arr[idx]+diff];
        auto it=upper_bound(nums.begin(),nums.end(),idx)-nums.begin();
        if(it==nums.size()){
                return dp[idx]=res;
        }
        res=max(res,1+f(arr,nums[it],n,diff,mp));
        return dp[idx]=res;
}
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,vector<int>> mp;
            int n=arr.size();
            for(int i=0;i<n;i++){
                    mp[arr[i]].push_back(i);
            }
            memset(dp,-1,sizeof(dp));
            long long res=0;
            for(int i=0;i<n;i++){
                    res=max(res,f(arr,i,n,difference,mp));
            }
            return res;
    }
};