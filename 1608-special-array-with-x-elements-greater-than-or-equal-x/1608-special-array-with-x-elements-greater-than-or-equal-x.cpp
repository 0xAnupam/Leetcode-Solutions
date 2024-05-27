class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),i=0,j=0;
        while(j<=nums.back()){
            while(i<n && nums[i]<=j)i++;
            if(n-i-1==j)return ++j;
            j++;
        }
        return -1;
    }
};