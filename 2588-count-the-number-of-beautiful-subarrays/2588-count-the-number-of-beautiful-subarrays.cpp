const int N=2e6+1;
long long mp[N];
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
            memset(mp,0,sizeof(mp));
            mp[0]++;
            long long res=0,x=0;
            for(auto &i:nums){
                    x^=i;
                    res+=mp[x];
                    mp[x]++;
            }
            return res;
    }
};