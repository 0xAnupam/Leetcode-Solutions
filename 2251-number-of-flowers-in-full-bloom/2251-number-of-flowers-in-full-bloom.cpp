class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> l,h;
            for(auto &i:flowers){
                    l.emplace_back(i[0]);
                    h.emplace_back(i[1]);
            }
            sort(l.begin(),l.end());
            sort(h.begin(),h.end());
            vector<int> res;
            for(auto &i:persons){
                    auto a=upper_bound(l.begin(),l.end(),i)-l.begin();
                    auto b=lower_bound(h.begin(),h.end(),i)-h.begin();
                    res.push_back(a-b);
            }
            return res;
    }
};