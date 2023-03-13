class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<long long> psum;
        long long sum=0;
            for(auto &i:arr){
                    sum+=i;
                    psum.push_back(sum);
                    
            }
            int res=1e6,n=arr.size();
            vector<int> dp(n+1,1e6);
            for(int i=n-1;i>=0;i--){
                    auto it=lower_bound(psum.begin(),psum.end(),psum[i]+target-arr[i])-psum.begin();
                    if(it<n && psum[it]-psum[i]+arr[i]==target){
                            
                            dp[i]=it-i+1;
                            res=min(res,dp[i]+dp[it+1]);
                    }
                    dp[i]=min(dp[i],dp[i+1]);
                    
            }
            
            if(res>=1e6){
                    return -1;
            }
            return res;
    }
};