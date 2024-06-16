class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<long long> fre(24,0);
        for(auto &i:hours)fre[i%24]++;
        long long res=(fre[0]*(fre[0]-1))/2+(fre[12]*(fre[12]-1))/2;
        for(int i=1;i<12;i++)res+=(fre[i]*fre[24-i]);
        return res;
    }
};