class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s;
            for(auto &i:nums1){
                    s.insert(i);
            }
            vector<int> res;
            for(auto &i:nums2){
                    auto p=s.upper_bound(i);
                    if(p==s.end()){
                            p=s.begin();
                    }
                    res.push_back(*p);
                    s.erase(p);
            }
            return res;
    }
};