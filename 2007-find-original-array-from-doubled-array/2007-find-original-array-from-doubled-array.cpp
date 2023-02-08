class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        multiset<int> s;
            for(auto &i:changed){
                    s.insert(i);
            }
            vector<int> res;
            while(s.size()){
                    auto p=*s.begin();
                    s.erase(s.begin());
                    auto P=s.find(2*p);
                    if(P==s.end()){
                            return {};
                    }
                    s.erase(P);
                    res.emplace_back(p);
            }
            return res;
    }
};