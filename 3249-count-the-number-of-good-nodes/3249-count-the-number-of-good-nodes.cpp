pair<int,int> dfs(int node,int par,vector<vector<int>> &adj){
    int x=-1;
    bool flag=1;
    int nodes=1,ans=0;
    for(auto &i:adj[node]){
        if(i!=par){
            auto it=dfs(i,node,adj);
            nodes+=it.first;
            ans+=it.second;
            if(x==-1){
                x=it.first;
            }
            else if(x!=it.first)flag=0;
        }
    }
    ans+=flag;
    return {nodes,ans};
}
class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        for(auto &i:edges){
            adj[i[0]].emplace_back(i[1]);
            adj[i[1]].emplace_back(i[0]);
        }
        return dfs(0,-1,adj).second;
    }
};