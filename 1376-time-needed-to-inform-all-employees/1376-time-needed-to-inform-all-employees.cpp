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
            queue<pair<int,int>> q;
            q.push({h,0});
            while(q.size()){
                    auto p=q.front();
                    q.pop();
                    for(auto &i:adj[p.first]){
                            time[i]=informTime[p.first]+p.second;
                            q.push({i,time[i]});
                    }
            }
            return *max_element(time.begin(),time.end());
                                    
    }
};