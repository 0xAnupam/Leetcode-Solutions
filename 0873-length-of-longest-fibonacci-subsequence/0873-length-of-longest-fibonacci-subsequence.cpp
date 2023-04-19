const int N=1e3+1;
int dp[N][N];
int f(vector<int> &arr,int i,int j,int n){
        if(dp[i][j]!=-1){
                return dp[i][j];
        }
        int p=arr[i]+arr[j];
        int it=lower_bound(arr.begin()+j+1,arr.end(),p)-arr.begin();
        if(it==n){
                return dp[i][j]=0;
        }
        if(arr[it]==p){
                return dp[i][j]=1+f(arr,j,it,n);
        }
        return dp[i][j]=0;
}

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        int n=arr.size(),res=0;
        for(int i=0;i<n-2;i++){
                for(int j=i+1;j<n-1;j++){
                        int p=f(arr,i,j,n);
                        if(p){
                                res=max(res,2+p);
                        }
                }
        }
            return res;
    }
};