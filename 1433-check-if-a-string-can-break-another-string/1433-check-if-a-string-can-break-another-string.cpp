bool Break(multiset<char>&a,multiset<char> b){
        for(auto &i:a){
                auto it=b.lower_bound(i);
                if(it==b.end()){
                        return 0;
                        
                }
                b.erase(it);
        }
        return 1;
}
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        multiset<char> a,b;
            for(auto &i:s1){
                    a.insert(i);
            }
            for(auto &i:s2){
                    b.insert(i);
            }
            return (Break(a,b) || Break(b,a));
    }
};