#define mod 1000000007
class Solution {
public:

 int power(int val, int po){
        long long ans = 1;
        
        while(po--){
            ans = (ans%mod*val%mod)%mod;
        }
        
        return ans;
    }
int n,sum=0;
   int dp[101][101][101];
   int find(vector<int>&nums,int k,int idx,int count)
   {
     if(k<0)
     return 0;
    
     if(k==0){
        return power(2,n-count);
     }
      if(idx==n)return 0;
      if(dp[k][idx][count]!=-1)
     return dp[k][idx][count]%mod;      
     int sum=0;
      sum=(sum+find(nums,k-nums[idx],idx+1,count+1))%mod;
      sum=(sum+find(nums,k,idx+1,count))%mod;
      return dp[k][idx][count]=sum;
   }

    int sumOfPower(vector<int>& nums, int k) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return find(nums,k,0,0)%mod;
    
    }
};
