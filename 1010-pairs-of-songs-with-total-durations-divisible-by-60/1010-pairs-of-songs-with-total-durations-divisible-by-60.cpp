class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,long long> mp;
            for(auto &i:time){
                    mp[i%60]++;
            }
            long long res=mp[0]*(mp[0]-1);
            res/=2;
            res+=((mp[30]*(mp[30]-1))/2);
            
            for(int i=1;i<30;i++){
                    res+=mp[i]*mp[60-i];
            }
            return res;
    }
};