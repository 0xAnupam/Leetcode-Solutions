const int maxN=1e6+1;
int fre[maxN];
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        memset(fre,0,sizeof(fre));
        map<int,long long> mp;
        long long res=0;
        for(auto &i:nums2)mp[i*k]++;
        for(auto &i:nums1)fre[i]++;
        for(auto &i:mp){
            for(int j=i.first;j<maxN;j+=i.first)res+=(i.second*fre[j]);
        }
        return res;
    }
};