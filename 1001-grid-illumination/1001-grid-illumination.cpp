int f(multiset<int> &a,multiset<int> &b,multiset<int> &c,multiset<int> &d,int x,int y,int n){
        if(a.find(x)!=a.end()){
                return 1;
        }
        if(c.find(x+y)!=c.end()){
                return 1;
        }
        if(b.find(y)!=b.end()){
                return 1;
        }
        if(d.find(n-x-1+y)!=d.end()){
                return 1;
        }
        return 0;
        
}
vector<pair<int,int>> moves={{0,0},{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> res;
            multiset<int> a,b,c,d;
            set<pair<int,int>> s;
        for(auto &i:lamps){
                if(s.find({i[0],i[1]})==s.end()){
                a.insert(i[0]);
                b.insert(i[1]);
                c.insert(i[0]+i[1]);
                d.insert(n-1-i[0]+i[1]);
                        s.insert({i[0],i[1]});
                }
        }                    
            for(auto &i:queries){
                    res.push_back(f(a,b,c,d,i[0],i[1],n));
                    int x,y;
                    for(auto &j:moves){
                            x=i[0]+j.first;
                            y=i[1]+j.second;
                            auto it=s.find({x,y});
                            if(it!=s.end()){
                                    s.erase(it);
                                    a.erase(a.find(x));
                                    b.erase(b.find(y));
                                    c.erase(c.find(x+y));
                                    d.erase(d.find(n-1-x+y));  
                            }
                    }
            }
        return res;
    }
};