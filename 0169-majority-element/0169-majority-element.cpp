class Solution{
    public:
        int majorityElement(vector<int> &nums){
            int n = 1;
            int ans = nums[0];
            for (int i = 1; i < nums.size(); i++){
                if (nums[i] == ans){
                    n++;
                }
                else{
                    n--;
                }
                if (n == 0){
                    n++;
                    ans = nums[i];
                }
            }
            return ans;
        }
};