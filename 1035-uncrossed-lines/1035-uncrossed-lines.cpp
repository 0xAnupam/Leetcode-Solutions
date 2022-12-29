int dp[501][501];
int f(vector<int> &a,vector<int> &b,int l,int h,int &n,int &m){
        if(l==n || h==m){
                return 0;
        }
        if(dp[l][h]!=-1){
                return dp[l][h];
        }
        if(a[l]!=b[h]){
                return dp[l][h]=max(f(a,b,l+1,h,n,m),f(a,b,l,h+1,n,m));
        }
        return dp[l][h]=1+f(a,b,l+1,h+1,n,m);
}
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
            int n=nums1.size(),m=nums2.size();
            return f(nums1,nums2,0,0,n,m);
    }
};