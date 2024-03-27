const long long pri= 837149;
const long long mod= 217191045809;
class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<pair<string,int>> vs;
            int n=wordsContainer.size();
            for(int i=0;i<n;i++){
                    vs.push_back({wordsContainer[i],i});
            }
            sort(vs.begin(),vs.end(),[](const pair<string,int> &a,const pair<string,int> &b){
               if(a.first.size()==b.first.size()){
                       return a.second<b.second;
               }    
                    return a.first.size()<b.first.size();
                    
            });
            reverse(vs.begin(),vs.end());
            
            map<long long ,int > mp;
            for(int i=0;i<n;i++){
                    long long p=0;
                    int m=vs[i].first.size();
                    for(int j=m-1;j>=0;j--){
                            p*=pri;
                            p%=mod;
                            p+=(vs[i].first[j]-'a'+1);
                            p%=mod;
                            mp[p]=vs[i].second;
                    }
            }
            vector<int> res;
            for(auto &i:wordsQuery){
                    long long p=0;
                    int m=i.size();
                    int ans=vs.back().second;
                    for(int j=m-1;j>=0;j--){
                            p*=pri;
                            p%=mod;
                            p+=(i[j]-'a'+1);
                            p%=mod;
                            if(mp.count(p)){
                                    ans=mp[p];
                            }
                            
                    }
                    
                    res.push_back(ans);
                    
            }
            
            return res;
    }
};