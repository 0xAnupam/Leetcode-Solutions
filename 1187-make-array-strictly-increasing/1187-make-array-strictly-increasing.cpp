const int N=2e3;
int dp[N][N][2];
int f(vector<int> &a,vector<int> &b,int i,int j,int n,int k){
        if(i==n){
                return 0;
        }
        int prev=a[i-1];
        if(k){
                prev=b[j];
        }
        if(dp[i][j][k]!=-1){
                return dp[i][j][k];
        }
        auto idx=upper_bound(b.begin()+j,b.end(),prev)-b.begin();
        int res=1e9;
        if(a[i]>prev){
                res=f(a,b,i+1,j,n,0);
        }
        if(idx<b.size()){
                res=min(res,1+f(a,b,i+1,idx,n,1));
        }
        return dp[i][j][k]=res;
        
}
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
            memset(dp,-1,sizeof(dp));
            int n=arr1.size();
            int res=min(f(arr1,arr2,1,0,n,0),1+f(arr1,arr2,1,0,n,1));
            return res>=1e9 ? -1:res;
    }
};