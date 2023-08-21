const int N=1e5+1;
long long dp[N][2];
const long long mod=1e9+7;
long long f(vector<int>& nums1, vector<int>& nums2,int idx,int k){
        if(k==0){
                if(dp[idx][k]!=-1){
                        return dp[idx][k];
                }
                if(idx==nums1.size()){
                        return 0;
                }
                auto it=lower_bound(nums2.begin(),nums2.end(),nums1[idx])-nums2.begin();
                if(it!=nums2.size() && nums2[it]==nums1[idx]){
                        return dp[idx][k]=nums1[idx]+max(f(nums1,nums2,idx+1,0),f(nums1,nums2,it+1,1));
                }
                return dp[idx][k]= nums1[idx]+f(nums1,nums2,idx+1,0);
        }
        else{   if(dp[idx][k]!=-1){
                        return dp[idx][k];
                }
                if(idx==nums2.size()){
                        return 0;
                }
                auto it=lower_bound(nums1.begin(),nums1.end(),nums2[idx])-nums1.begin();
                if(it!=nums1.size() && nums1[it]==nums2[idx]){
                        return dp[idx][k]=nums2[idx]+max(f(nums1,nums2,idx+1,1),f(nums1,nums2,it+1,0));
                }
                return dp[idx][k]=nums2[idx]+f(nums1,nums2,idx+1,1);
        }
}
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
            memset(dp,-1,sizeof(dp));
        return max(f(nums1,nums2,0,0)%mod,f(nums1,nums2,0,1)%mod);
    }
};