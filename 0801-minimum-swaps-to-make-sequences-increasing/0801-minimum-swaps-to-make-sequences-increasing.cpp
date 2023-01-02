class Solution {
public: int dp[100001][2];
        int ways(vector<int>& nums1, vector<int>& nums2,int ind,int n,int a,int b){
                if(ind==n){
                        return 0;
                }
                if(ind==0){
                        return min(ways(nums1,nums2,ind+1,n,nums1[ind],nums2[ind]),1+
                                  ways(nums1,nums2,ind+1,n,nums2[ind],nums1[ind]));
                }
                
                if(a>=nums1[ind]|| b>=nums2[ind]){
                        if(dp[ind][1]!=-1){
                        return dp[ind][1];
                          }
         return dp[ind][1]= 1+ways(nums1,nums2,ind+1,n,nums2[ind],nums1[ind]);
                }
                if(dp[ind][0]!=-1){
                        return dp[ind][0];
                }
                int k=1e5;
                if(a<nums2[ind] && b<nums1[ind]){
                        k=1+ways(nums1,nums2,ind+1,n,nums2[ind],nums1[ind]);
                }
             return dp[ind][0]=min(ways(nums1,nums2,ind+1,n,nums1[ind],nums2[ind]),k);
        }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
            memset(dp,-1,sizeof(dp));
        return ways(nums1,nums2,0,nums1.size(),-1,-1);
    }
};