class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> res(k,0);
            map<int,set<int>> mp;
            for(auto &i:logs){
                    mp[i[0]].insert(i[1]);
            }
            for(auto &i:mp){
                    k=i.second.size();
                    res[k-1]++;
            }
            return res;
    }
};