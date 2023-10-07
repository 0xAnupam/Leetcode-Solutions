class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
            int res=0;
            for(auto &i:answers){
                    mp[i]++;
                    if(mp[i]>i){
                            res+=(i+1);
                            mp.erase(i);
                    }
            }
            for(auto &i:mp){
                    res+=(i.first+1);
            }
            return res;
    }
};