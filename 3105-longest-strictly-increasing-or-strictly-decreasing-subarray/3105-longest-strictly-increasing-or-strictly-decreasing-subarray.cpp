int f(vector<int> &nums){
        int n=nums.size();
        int i=0,res=0;
        while(i<n){
                int p=nums[i]-1,cnt=0;
                while(i<n && nums[i]>p){
                        p=nums[i];
                        nums[i]*=-1;
                        i++;
                        cnt++;
                }
                res=max(res,cnt);
        }
        return res;
}
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        return max(f(nums),f(nums));
    }
};