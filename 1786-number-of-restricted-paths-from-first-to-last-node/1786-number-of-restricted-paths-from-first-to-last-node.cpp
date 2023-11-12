const int mod=1e9+7;
int paths(int node,vector<pair<int,int>>* adj,vector<int> &dis,vector<int> &dp){
        if(dp[node]!=-1){
                return dp[node];
        }
        int res=0;
        for(auto &i:adj[node]){
                if(dis[i.first]<dis[node]){
                        res+=paths(i.first,adj,dis,dp);
                        res%=mod;
                }
        }
        return dp[node]=res;
}
class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
            for(auto &i:edges){
                    adj[i[0]].push_back({i[1],i[2]});
                    adj[i[1]].push_back({i[0],i[2]});
            }
            vector<int> dis(n+1,INT_MAX);
            dis[n]=0;
            priority_queue<pair<int,int>> pq;
            pq.push({0,n});
            while(pq.size()){
                    auto p=pq.top();
                    pq.pop();
                    p.first*=-1;
                    if(dis[p.second]<p.first){
                            continue ;
                    }
                    for(auto &i:adj[p.second]){
                            if(dis[i.first]>i.second+p.first){
                                    dis[i.first]=i.second+p.first;
                                    pq.push({-dis[i.first],i.first});
                            }
                    }
            }
            vector<int> dp(n+1,-1);
            dp[n]=1;
            return paths(1,adj,dis,dp);
            
    }
};