class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> mp;
            for(auto&i:nums){
                    mp[i]++;
            }
            int n=0;
            for(auto &i:mp){
                    n=max(n,i.second);
            }
            vector<vector<int>> res(n,vector<int>());
            for(auto &i:mp){
                    
                    for(int l=0;l<i.second;l++){
                            res[l].emplace_back(i.first);
                    }
            }
            return res;
    }
};