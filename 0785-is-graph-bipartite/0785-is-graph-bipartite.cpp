void dfs(int node,vector<vector<int>> &adj,int col,vector<bool> &vis,vector<char>&color){
        if(vis[node]){
                return ;
        }
        vis[node]=1;
        if(col&1){
                color[node]='R';
        }
        else{
                color[node]='B';
        }
        col++;
        for(auto &i:adj[node]){
                dfs(i,adj,col,vis,color);
        }
        
}
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
            int n=graph.size();
        vector<vector<int>> adj(n,vector<int>());
            int k=0;
            for(auto &i:graph){
                   for(auto &j:i){
                           adj[k].push_back(j);
                           adj[j].push_back(k);
                   }
                    k++;
                  //  adj[i[1]].push_back(i[0]);
            }
            vector<bool> vis(n,0);
            vector<char> color(n);
            for(int i=0;i<n;i++){
                    if(vis[i]==0){
                            dfs(i,adj,1,vis,color);
                    }
                    for(auto &j:adj[i]){
                            if(color[j]==color[i]){
                                    return 0;
                            }
                    }
            }
            return 1;
            
    }
};