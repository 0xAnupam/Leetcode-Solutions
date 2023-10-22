int f(int l,int r,vector<int> &nums){
        
        if(l>r){
                return 5001;
        }
        if(l==r){
                return nums[l];
        }
        if(r-l==1){
                return min(nums[l],nums[r]);
        }
        int m=(l+r)/2;
        if(nums[l]==nums[m] && nums[m]==nums[r]){
                return min({nums[m],f(l,m-1,nums),f(m+1,r,nums)});
        }
        else if(nums[l]<= nums[m] && nums[m]>nums[r]){
                return f(m,r,nums);
        }
        return f(l,m,nums);
}
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
            return f(0,n-1,nums);
    }
};