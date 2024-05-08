class Solution {
public:
    int nthUglyNumber(int n) {
        long long res=1;
            set<long long> s={1};
            while(n--){
                    res=*s.begin();
                    s.erase(s.begin());
                    s.insert(2*res);
                    s.insert(3*res);
                    s.insert(5*res);
            }
            return res;
            
    }
};