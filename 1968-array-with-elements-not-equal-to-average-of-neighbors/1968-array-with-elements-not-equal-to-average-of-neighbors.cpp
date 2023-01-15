class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
     sort(nums.rbegin(),nums.rend());
            vector<int> res(nums.size());
            int n=nums.size();
            int j=0;
            for(int i=0;i<n;i+=2){
                    res[i]=nums[j++];
            }
            for(int i=1;i<n;i+=2){
                    res[i]=nums[j++];
            }
            return res;
    }
};