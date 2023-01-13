const int N=1e5+1;
int dp[N];
vector<vector<int>> P(N,vector<int>());
int f(int node,vector<vector<int>> &adj,string &s){     
        if(dp[node]!=-1){
         return dp[node];
}
        int res=1;
        for(auto &i:adj[node]){
                if(s[i]!=s[node]){
                res=max(res,1+f(i,adj,s));
                        P[node].push_back(1+f(i,adj,s));
                }
        }
         return dp[node]=res;
}
int f(vector<int>&p){
        if(p.size()<2){
                return 0;
        }
        sort(p.rbegin(),p.rend());
        return p[0]+p[1]-1;
}
class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
           for(int i=0;i<n;i++){
                   while(P[i].size()){
                           P[i].pop_back();
                   }
           }
           vector<vector<int>> adj(n,vector<int>());
            for(int i=1;i<n;i++){
                    adj[parent[i]].push_back(i);
            }
            memset(dp,-1,sizeof(dp));
            int res=0;
            for(int i=0;i<n;i++)
            {
                    res=max(res,f(i,adj,s));
            }
            for(int i=0;i<n;i++){
                    
                    res=max(res,f(P[i]));
            }
            return res;
    }
};