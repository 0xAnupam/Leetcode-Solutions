class Solution {
public:
    int f(int n,int src,vector<vector<pair<int,int>>> &v , int distanceThreshold){
        vector<int> dis(n,1e9);
        dis[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            if(dis[p.second]<p.first)continue ;
            for(auto &i:v[p.second]){
                if(dis[i.first]>i.second+p.first){
                    dis[i.first]=i.second+p.first;
                    pq.push({dis[i.first],i.first});
                }
            }
        }
        dis[src]=1e9;
        int ans=0;
        for(int i=0;i<n;i++)ans+=(dis[i]<=distanceThreshold);
        return ans;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int x=n,ans=-1;
        vector<vector<pair<int,int>>> v(n);
        for(auto &i:edges){
            v[i[0]].push_back({i[1],i[2]});
            v[i[1]].push_back({i[0],i[2]});
        }
        for(int i=0;i<n;i++){
            int y=f(n,i,v,distanceThreshold);
            if(y<=x){
                x=y;
                ans=i;
            }
        }
        return ans;
    }
};