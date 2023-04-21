int f(vector<int> &nums,int idx,int n,int x){
        if(idx==n){
                return x;
        }
        return f(nums,idx+1,n,(x^nums[idx]))+f(nums,idx+1,n,x);
}
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
            return f(nums,0,n,0);
    }
};