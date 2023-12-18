class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
            long long res=(nums[nums.size()-1])*(nums[nums.size()-2]);
            res-=(nums[0]*nums[1]);
            return res;
    }
};