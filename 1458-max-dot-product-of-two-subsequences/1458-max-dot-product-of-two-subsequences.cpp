const int N=501;
int dp[N][N][2];
int f(vector<int>& nums1, vector<int>& nums2,int i,int j,int k){
        if(i==nums1.size() || j==nums2.size()){
                return k==1 ? 0 : -1e6;
        }
        if(dp[i][j][k]!=-1){
                return dp[i][j][k];
        }
        int take=nums1[i]*nums2[j]+f(nums1,nums2,i+1,j+1,1);
        int not_take=max(f(nums1,nums2,i,j+1,k),f(nums1,nums2,i+1,j,k));
        return dp[i][j][k]=max(take,not_take);
}
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
            memset(dp,-1,sizeof(dp));
        return f(nums1,nums2,0,0,0);
    }
};