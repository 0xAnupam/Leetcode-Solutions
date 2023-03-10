long long mod=1e9+7;
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        vector<int> l;
            for(int i=0;i<22;i++){
                    l.push_back((1<<i));
            }
            map<int,long long> mp;
            for(auto &i:deliciousness){
                    mp[i]++;
            }
            long long res=0,zero=mp[0];
            mp.erase(0);
            for(auto &i:mp){
                    if((i.first&(i.first-1))==0){
                                    res+=i.second*zero;
                                    res%=mod;    
                            }
                    auto it=upper_bound(l.begin(),l.end(),i.first)-l.begin();
                    while(it>=0 ){
                            if(l[it]==2*i.first){
                                    res+=(i.second*(i.second-1))/2;
                                    res%=mod;
                            }
                            else if(mp.find(l[it]-i.first)!=mp.end()){
                                    res+=i.second*mp[l[it]-i.first];
                            }
                            it--;
                            res%=mod;
                    }
            }
            return res;
    }
};