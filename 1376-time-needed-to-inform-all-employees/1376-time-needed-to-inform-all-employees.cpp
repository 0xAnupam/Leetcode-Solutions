class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> time(n,0);
            vector<vector<int>> adj(n,vector<int>());
            int h=0;
            for(int i=0;i<n;i++){
                    if(manager[i]==-1){
                            h=i;
                    }
                    else{
                            adj[manager[i]].push_back(i);
                    }
            }
            priority_queue<pair<int,int>> q;
            q.push({0,h});
            while(q.size()){
                    auto p=q.top();
                    q.pop();
                    if(time[p.second]+p.first<0){
                            continue ;
                    }
                    for(auto &i:adj[p.second]){
                            time[i]=informTime[p.second]-p.first;
                            q.push({-time[i],i});
                    }
            }
            return *max_element(time.begin(),time.end());
                                    
    }
};