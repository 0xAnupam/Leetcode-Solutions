class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        set<pair<int,int>> s;
            int j=0,n=intervals.size();
            for(auto &i:intervals){
                    s.insert({i[0],j++});
            }
            vector<int>res(n,-1);
            j=0;
            for(auto &i:intervals){
                    auto p=s.lower_bound({i[1],0});
                    if(p!=s.end()){
                        res[j]=(*p).second;            
                    }
                    j++;
            }
            return res;
            
            
    }
};