class Solution {
public:
    vector<int> f(int src,vector<vector<pair<int,int>>> &adj){
        vector<int> dis(26,INT_MAX);
        dis[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            if(dis[p.second]<p.first)continue ;
            for(auto &i:adj[p.second]){
                if(dis[i.first]>i.second+p.first){
                    dis[i.first]=i.second+p.first;
                    pq.push({dis[i.first],i.first});
                }
            }
        }
        return dis;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>> adj(26);
        vector<vector<int>> dis(26);
        int n=cost.size();
        for(int i=0;i<n;i++){
            adj[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        for(int i=0;i<26;i++)dis[i]=f(i,adj);
        long long ans=0;
        n=source.size();
        for(int i=0;i<n;i++){
            if(dis[source[i]-'a'][target[i]-'a']==INT_MAX)return -1;
            ans+=dis[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};