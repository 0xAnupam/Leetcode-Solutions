class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<long long ,vector<int> > mp;
            for(auto &i:buildings){
                    mp[i[0]].push_back(i[2]);
                    mp[i[1]].push_back(-i[2]);
            }
            map<long long,int> m;
            multiset<int> s;
            s.insert(0);
            for(auto &i:mp){
                    for(auto &j:i.second){
                            if(j<0){
                                   s.erase(s.find(-j));
                            }
                            else{
                                    s.insert(j);
                            }
                    }
                    m[i.first]=max(m[i.first],(*s.rbegin()));
            }
            int p=0;
            vector<vector<int>> res;
            for(auto &i:m){
                    if(p!=i.second){
                            vector<int> t;t.push_back(i.first);
                            t.push_back(i.second);
                            res.push_back(t);
                            p=i.second;
                    }
            }
            return res;
    }
};