class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> res;
            int n=(1<<maximumBit)-1,x=0;
            for(auto &i:nums){
                    x^=i;
                    res.push_back((n^x));
            }
            reverse(res.begin(),res.end());
            return res;
    }
};