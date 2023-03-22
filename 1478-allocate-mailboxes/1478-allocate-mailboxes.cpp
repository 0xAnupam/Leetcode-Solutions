int dp[101][101];
int cost(vector<int> &arr,int l,int r){
        int median=0;
        if((r-l)%2==0){
                median=arr[l+(r-l)/2];
        }
        else{
                median=(arr[l+(r-l)/2]+arr[l+1+(r-l)/2])/2;
        }
        int res=0;
        for(int i=l;i<=r;i++){
                res+=abs(arr[i]-median);
        }
        return res;
}
int f(vector<int> &arr,int idx,int n,int k){
        if(idx==n){
                return 0;
        }
        if(k==0){
                return 1e7;
        }
        if(dp[idx][k]!=-1){
                return dp[idx][k];
        }
        int res=1e7;
        for(int i=idx;i<n-k+1;i++){
             
                res=min(res,cost(arr,idx,i)+f(arr,i+1,n,k-1));
        }
        return dp[idx][k]=res;
}
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(),houses.end());
            memset(dp,-1,sizeof(dp));
            return f(houses,0,houses.size(),k);
    }
};