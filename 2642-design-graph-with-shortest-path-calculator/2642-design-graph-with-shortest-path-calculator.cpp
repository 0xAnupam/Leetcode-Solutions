vector<vector<pair<int,int>>> adj;
const long long BIG=1e18;
long long dis[1000000];
int y;
long long distance(int src,int dst){
        int n=adj.size();
        for(int i=0;i<y;i++){
                dis[i]=BIG;
        }
        priority_queue<pair<int,int>> pq;
        dis[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
                auto p=pq.top();
                pq.pop();
                long long D=-p.first;
                if(dis[p.second]<D){
                        continue ;
                }
                for(auto &i:adj[p.second]){
                        if(dis[i.first]>D+i.second){
                                dis[i.first]=D+i.second;
                                pq.push({-dis[i.first],i.first});
                        }
                }
        }
        return dis[dst]==BIG ? -1:dis[dst];
}
class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
            y=n;
        vector<vector<pair<int,int>>> t(n,vector<pair<int,int>>());
            for(auto &i:edges){
                    t[i[0]].push_back({i[1],i[2]});
            }
            adj=t;
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        return distance(node1,node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */