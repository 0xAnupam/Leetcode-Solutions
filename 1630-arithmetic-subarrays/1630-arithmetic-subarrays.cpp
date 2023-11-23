class Solution{
    public:
        bool AP(vector<int> nums, int l, int h){
            if (l == h || l == nums.size() - 1){
                return 0;
            }
            sort(nums.begin() + l, nums.begin() + h + 1);
            int d = nums[l + 1] - nums[l];
            for (int i = l; i < h; i++){
                if (nums[i + 1] - nums[i] != d){
                    return 0;
                }
            }
            return 1;
        }
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector< int > &r){
        vector<bool> res;
        int n = l.size();
        for (int i = 0; i < n; i++){
            res.push_back(AP(nums, l[i], r[i]));
        }
        return res;
    }
};