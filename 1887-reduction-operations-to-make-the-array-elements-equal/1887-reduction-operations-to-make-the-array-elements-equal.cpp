class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
            int res=0;
            int i=0,n=nums.size();
            while(i<n){
                    res+=i;
                    int p=nums[i];
                    while(i<n && nums[i]==p){
                            i++;
                    }
            }
            return res;
    }
};