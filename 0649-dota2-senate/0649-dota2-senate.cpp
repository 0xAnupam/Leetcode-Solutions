void f(set<int>&r,set<int>&d,set<int>&a,string &s){
    auto it=a.begin();
        while(it!=a.end() && r.size() && d.size()){
        if(s[*it]=='R'){
            auto p=d.lower_bound(*it);
            if(p==d.end()){
                p=d.begin();
            }
            a.erase(*p);
            d.erase(p);
        }
        else{
            auto p=r.lower_bound(*it);
            if(p==r.end()){
                p=r.begin();
            }
            a.erase(*p);
            r.erase(p);
        }
        
        it=a.upper_bound(*it);
    }
}
class Solution {
public:
    string predictPartyVictory(string senate) {
        set<int> r,d,a;
        int n=senate.size();
        for(int i=0;i<n;i++){
            if(senate[i]=='R'){
                r.insert(i);
            }
            else{
                d.insert(i);
            }
            a.insert(i);
        }
        while(r.size() && d.size()){
            f(r,d,a,senate);
        }
        return r.size() ? "Radiant" : "Dire";
    }
};
