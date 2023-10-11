const int N=1e6+1000;
int dp[N];
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        vector<pair<int,int>> adj[N];
            
            int n=routes.size();
            for(int i=0;i<n;i++){
                    int m=routes[i].size();
                    dp[routes[i][m-1]]=INT_MAX;
                    for(int j=0;j<m-1;j++){
                            dp[routes[i][j]]=INT_MAX;
                            adj[routes[i][j]].push_back({routes[i][j+1],i});
                    }
                    if(m>1){
                        adj[routes[i][m-1]].push_back({routes[i][0],i});
                    }
            }
            if(dp[target]!=INT_MAX){
                    return -1;
            }
            priority_queue<vector<int>> pq;
            dp[source]=0;
            pq.push({0,source,-1});
            vector<int> p(3),q(3);
            while(pq.size()){
                    p=pq.top();
                    pq.pop();
                    int dis=-p[0];
                    if(dp[p[1]]<dis){
                            continue ;
                    }
                    for(auto &i:adj[p[1]]){
                            if(dp[i.first]>=dis+(i.second!=p[2])){
                                    dp[i.first]=dis+(i.second!=p[2]);
                                    q[0]=-dp[i.first];
                                    q[1]=i.first;
                                    q[2]=i.second;
                                    pq.push(q);
                            }
                    }
                    
                    
            }
            
            return dp[target]!=INT_MAX ? dp[target] : -1;
    }
};