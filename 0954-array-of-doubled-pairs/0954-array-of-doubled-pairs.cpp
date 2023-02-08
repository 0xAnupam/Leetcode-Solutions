class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        multiset<int> s;
            for(auto &i:arr){
                    s.insert(i);
            }
            while(s.size()){
                    int p=*s.begin();
                    if(p<0){
                            if(abs(p)&1){
                                    return 0;
                            }
                            p/=2;
                    }
                    else{
                            p*=2;
                    }
                    s.erase(s.begin());
                    auto P=s.find(p);
                    if(P==s.end()){
                            return 0;
                    }
                    s.erase(P);
            }
            return 1;
    }
};