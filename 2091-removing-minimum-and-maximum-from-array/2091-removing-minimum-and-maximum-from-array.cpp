class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int a=min_element(nums.begin(),nums.end())-nums.begin(),
            b=max_element(nums.begin(),nums.end())-nums.begin();
            return min({max(a,b)+1,n-min(a,b),a+1+n-b,b+1+n-a});
    }
};