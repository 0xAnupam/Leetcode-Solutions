class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> edges(n,vector<pair<int,int>>());
            for(auto &i:flights){
                    edges[i[0]].push_back({i[1],i[2]});
            }
            vector<int> cost(n,1e9),K_arr(n,-1);
            queue<pair<int,pair<int,int>>> q;
            q.push({src,{0,k+1}});
            cost[src]=0;
            K_arr[src]=k+1;
            while(q.size()){
                    auto p=q.front();
                    q.pop();
                    int node=p.first;
                    int mon=p.second.first;
                    int K=p.second.second-1;
                    for(auto &i:edges[node]){
                           
                            if(K>=0 && (cost[i.first]>mon+i.second || (cost[i.first]==mon+i.second && K_arr[i.first]<K))){               
                                    K_arr[i.first]=K;
                                    cost[i.first]=mon+i.second;
                                    q.push({i.first,{cost[i.first],K}});
                                    
                            }
                    }
            }
           
            return cost[dst]==1e9? -1:cost[dst];
    }
};