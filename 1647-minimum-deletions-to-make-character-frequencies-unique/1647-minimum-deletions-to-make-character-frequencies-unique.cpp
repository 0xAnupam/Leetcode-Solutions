
class Solution {
public:
    int minDeletions(string &s) {
        vector<int> f(26,0);
            for(auto &i:s){
                    f[i-'a']++;
            }
            map<int,int> mp;
            int res=0;
            for(auto &i:f){
                    if(i){
                    mp[-i]++;}
            }
            for(auto &i:mp){
                    res+=i.second-1;
                    if( i.first+1<0 && i.second>1){
                            mp[i.first+1]+=(i.second-1);
                    }
                    
            }
            return res;
    }
};