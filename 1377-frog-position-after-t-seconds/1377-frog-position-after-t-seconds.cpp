double dfs(int node,int par,vector<vector<int>>& adj, int t, int target) {
        if(t==0){
                return target==node;
        }
        double cnt=0,res=0;
        for(auto &i:adj[node]){
                if(i!=par){
                        cnt++;
                        res+=dfs(i,node,adj,t-1,target);
                }
        }
        if(cnt==0){
                return node==target;
        }
        res/=cnt;
        return res;
}
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n+1);
            for(auto &i:edges){
                  
                    adj[i[0]].emplace_back(i[1]);
                    adj[i[1]].emplace_back(i[0]);
            }
            return dfs(1,0,adj,t,target);
    }
};