class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
            for(auto &i:nums)k^=i;
            return __builtin_popcount(k);
    }
};