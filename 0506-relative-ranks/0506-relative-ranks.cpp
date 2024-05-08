class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
           int n=score.size();
            vector<pair<int,int>> v(n);
            for(int i=0;i<n;i++)v[i]={score[i],i};
            sort(v.rbegin(),v.rend());
            vector<string> res(n);
            vector<string> gg={"Gold Medal","Silver Medal","Bronze Medal"};
            for(int i=4;i<=n;i++)gg.push_back(to_string(i));
            int j=0;
            for(auto &i:v){
                    res[i.second]=gg[j++];
            }
            return res;
    }
};