class Solution {
public:
    int findGCD(vector<int>& nums) {
        int l=*min_element(nums.begin(),nums.end()),h=*max_element(nums.begin(),nums.end());
            return __gcd(l,h);
    }
};