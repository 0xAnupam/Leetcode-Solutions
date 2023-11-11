class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,int> mp;
        unordered_map<int,vector<int>> adj;
            vector<int> res;
        for(auto &i:adjacentPairs){
                adj[i[0]].push_back(i[1]);
                adj[i[1]].push_back(i[0]);
                mp[i[0]]++;
                mp[i[1]]++;
        }
            int st=0;
            for(auto &i:mp){
                    if(i.second==1){
                            st=i.first;
                    }
            }
            queue<pair<int,int>> q;
            q.push({st,st});
            while(q.size()){
                    auto p=q.front();
                    q.pop();
                    res.emplace_back(p.first);
                    for(auto &i:adj[p.first]){
                            if(i!=p.second){
                                    q.push({i,p.first});
                            }
                    }
            }
            return res;
            
    }
};