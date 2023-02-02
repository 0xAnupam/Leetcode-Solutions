class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
            
    int n=nums.size();
    vector<int> dp(n,1),arr(n,0);
            dp[n-1]=1;
            for(int i=n-2;i>=0;i--){
                    for(int j=i+1;j<n;j++){
                            if(nums[i]<nums[j]){
                                    
                                    dp[i]=max(dp[i],1+dp[j]);
                            }
                    }
            }
            int maxi=*max_element(dp.begin(),dp.end()),cnt=0;
            arr[n-1]=1;
             for(int i=n-1;i>=0;i--){
                    for(int j=n-1;j>i;j--){
                           
                            if(nums[i]<nums[j]){
                                   if(dp[i]==1+dp[j]){
                                           arr[i]+=arr[j];
                                   }
                                   
                            }
                    }
                     arr[i]=max(arr[i],1);
                     if(maxi==dp[i]){
                             cnt+=arr[i];
                     }
                    
            }
            
            return cnt;
    }
};