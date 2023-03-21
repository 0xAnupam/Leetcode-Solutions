class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<5){
                return 0;
        }
            sort(nums.begin(),nums.end());
            int n=nums.size();
            int res=2e9;
            int i=n-4,j=0;
            while(i<n){
                    res=min(res,nums[i]-nums[j]);
                    i++;
                    j++;
            }
            return res;
    }
};