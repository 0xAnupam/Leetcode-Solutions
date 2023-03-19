long long dp[21];

long long f(vector<int> &nums,int k,int idx,int n){
        if(idx==n){
                return 0;
        }
        
        long long res=1;
        int mark[n];
        memset(mark,-1,sizeof(mark));
        for(int i=idx+1;i<n;i++){
                if(nums[i]!=-1 && nums[idx]==nums[i]-k){
                        mark[i]=nums[i];
                        nums[i]=-1;
                }
        }
        for(int i=idx+1;i<n;i++){
                if(nums[i]!=-1){
                        res+=f(nums,k,i,n);
                }
        }
        for(int i=idx+1;i<n;i++){
                if(mark[i]!=-1){
                        nums[i]=mark[i];
                }
        }
        return dp[idx]=res;
}
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
       //     memset(mark,-1,sizeof(mark));
        long long res=0,n=nums.size();
            for(int i=0;i<n;i++){
                    res+=f(nums,k,i,n);
            }
            return res;
    }
};