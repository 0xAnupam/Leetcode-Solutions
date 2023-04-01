map<int,vector<int>> mp;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class Solution {
public:
    Solution(vector<int>& nums) {
        mp.clear();
        int n=nums.size();
            for(int i=0;i<n;i++){
                    mp[nums[i]].push_back(i);
            }
    }
    
    int pick(int target) {
        auto &p=mp[target];
            int n=p.size();
            return p[uniform_int_distribution<int>(0, n-1)(rng)];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */