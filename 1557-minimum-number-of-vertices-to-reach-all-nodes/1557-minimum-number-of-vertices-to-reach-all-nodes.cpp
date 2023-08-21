void dfs(int node,vector<int>* adj,int* vis){
        if(vis[node]){
                return ;
        }
        vis[node]=1;
        for(auto &i:adj[node]){
                dfs(i,adj,vis);
        }
}
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
            int degree[n];
            memset(degree,0,sizeof(degree));
            for(int i=0;i<edges.size();i++){
                    adj[edges[i][0]].push_back(edges[i][1]);
                    degree[edges[i][1]]++;
            }
            int visited[n];
            vector<int> res;
            memset(visited,0,sizeof(visited));
            for(int i=0;i<n;i++){
                    if(degree[i]==0 && visited[i]==0){
                          res.emplace_back(i);
                            dfs(i,adj,visited);
                    }
            }
            return res;
    }
};