class Solution {
public:
    int dfs(int node,vector<bool> & vis , vector<vector<pair<int,int>>> &adj){
        int ans=0;
        for(auto &i:adj[node]){
            if(vis[i.first])continue ;
            vis[i.first]=1;
            ans+=i.second;
            ans+=dfs(i.first,vis,adj);
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> d(n,0);
        for(auto &i:connections){
            adj[i[0]].push_back({i[1],1});
            adj[i[1]].push_back({i[0],0});
            d[i[0]]++;
            d[i[1]]++;
        }
        int ans=0;
        vector<bool> vis(n,false);
        vis[0]=1;
        return dfs(0,vis,adj);
        
    }
};