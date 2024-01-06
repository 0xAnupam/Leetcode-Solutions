long long dp[50001];
long long fun(vector<pair<pair<int,int>,int>> &adj,int ind,int &n){
        if(ind==n){
                return 0;
        }
        if(dp[ind]!=-1){
                return dp[ind];
        }
        
        long long res=fun(adj,ind+1,n),profit=adj[ind].second,t=adj[ind].first.second;
        int l=ind+1,h=n-1,m;
        while(l<=h){
                m=(l+h)/2;
                if(adj[m].first.first<t){
                        l=m+1;
                }
                else{
                        h=m-1;
                }
        }
       
        return dp[ind]=max(res,profit+fun(adj,l,n));
        
}
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<pair<int,int>,int>> adj;
            memset(dp,-1,sizeof(dp));
            int n=startTime.size();
            for(int i=0;i<n;i++){
                    adj.push_back({{startTime[i],endTime[i]},profit[i]});
            }
            sort(adj.begin(),adj.end());
            return fun(adj,0,n);
    }
};