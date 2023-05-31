class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(auto &i:meetings){
                adj[i[1]].push_back({i[0],i[2]});
                adj[i[0]].push_back({i[1],i[2]});
        }      
            vector<int> dis(n,1e9);
            
            priority_queue<pair<int,int>> pq;
            dis[0]=0;
            dis[firstPerson]=0;
            pq.push({0,0});
            pq.push({0,firstPerson});
            while(pq.size()){
                    auto p=pq.top();
                    pq.pop();
                    int time=-p.first;
                    if(time>dis[p.second]){
                            continue ;
                    }
                    for(auto &i:adj[p.second]){
                            if(i.second>=time && dis[i.first]>i.second){
                                    dis[i.first]=i.second;
                                    pq.push({-dis[i.first],i.first});
                            }
                    }
            }
            vector<int> res;
            for(int i=0;i<n;i++){
                    
                    if(dis[i]<1e9){
                            res.push_back(i);
                    }
            }
            return res;
    }
};