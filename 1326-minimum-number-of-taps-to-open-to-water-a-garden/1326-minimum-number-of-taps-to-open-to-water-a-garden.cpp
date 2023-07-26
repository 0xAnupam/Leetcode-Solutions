const int N=1e4+1;
int dp[N];
int f(int idx,int n,vector<int> &arr){
        if(idx>n){
                return 0;
        }
       
        if(dp[idx]!=-1){
                return dp[idx];
        }
        int N=min(idx+101,n+1),res=1e9,l=max(0,idx-101);
        for(int i=l;i<=idx;i++){
                if(arr[i] && idx-i<=arr[i]){
                        res=min(res,1+f(i+arr[i]+1,n,arr));
                }
        }
        for(int i=idx;i<N;i++){
                if(arr[i]&& i-idx<arr[i]){
                        res=min(res,1+f(i+arr[i]+1,n,arr));
                }
        }
        return dp[idx]=res;
}
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
            memset(dp,-1,sizeof(dp));
            int res=1e9;
            for(int i=0;i<=n;i++){
                    if(ranges[i]>=i){
                            res=min(res,1+f(i+ranges[i]+1,n,ranges));
                    }
            }
            
            return res> n ? -1:res;
    }
};