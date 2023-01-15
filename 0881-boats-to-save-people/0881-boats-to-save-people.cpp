class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        multiset<int> s;
        int res=0;
            for(auto &i:people){
                    s.insert(-i);
            }
            while(s.size()){
                    res++;
                    int cnt=0,l=0;
                    while(l<2 && s.size() && s.lower_bound(cnt-limit)!=s.end() ){
                           auto p=s.lower_bound(cnt-limit);
                            cnt-=*p;
                            s.erase(p);
                            l++;
                    }
                    
            }
            return res;
    }
};