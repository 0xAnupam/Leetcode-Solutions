const int mod=1e9+7;
const int N=1e3+1;
int dp[N];
int f(int idx,vector<int>* adj){
        if(dp[idx]!=-1){
                return dp[idx];
        }
        int res=1,n=adj[idx].size();
        for(int i=0;i<n;i+=2){
                int Gg=(f(adj[idx][i],adj)*1LL*f(adj[idx][i+1],adj))%mod;
                res+=Gg;
                res%=mod;
                if(adj[idx][i]!=adj[idx][i+1]){
                        res+=Gg;
                        res%=mod;
                }
        }
        return dp[idx]=res;
}
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
            vector<int> adj[n];
            unordered_map<long long,int> mp;
            for(int i=0;i<n;i++){
                    dp[i]=-1;
                    mp[arr[i]]=i;
            }
            for(int i=0;i<n;i++){
                    for(int j=i;j<n;j++){
                            long long p=arr[i]*1LL*arr[j];
                            if(p<mod && mp.find(p)!=mp.end()){
                                    adj[mp[p]].push_back(i);
                                    adj[mp[p]].push_back(j);
                            }
                    }
            }
            int res=0;
            for(int i=0;i<n;i++){
                    res+=f(i,adj);
                    res%=mod;
            }
            return res;
    }
};