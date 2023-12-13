
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
            map<long long,long long> sum;
            for(auto &i:segments){
                    sum[i[0]]+=i[2];
                    sum[i[1]]-=i[2];
            }
            vector<vector<long long>> res;
            long long a=-1,d=0;
            for(auto &i:sum){
                    if(d)res.push_back({a,i.first,d});
                    a=i.first;d+=i.second;
            }
            return res;
    }
};