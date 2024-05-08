class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> res;
            set<long long> s={1};
            while(res.size()<n){
                    auto it=*s.begin();
                    s.erase(s.begin());
                    res.emplace_back(it);    
                    s.insert(2*it);
                    s.insert(3*it);
                    s.insert(5*it);
            }
            return res[n-1];
            
    }
};