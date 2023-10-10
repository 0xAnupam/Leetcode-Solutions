
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
            vector<int> res(n);
            long long b=0,a=0;
            for(int i=0;i<n;i++){
                    b+=nums[i];
            }
            for(int i=0;i<n;i++){
                    res[i]=(nums[i]*1LL*i-a)+(b-(n-i)*1LL*nums[i]);
                    b-=nums[i];
                    a+=nums[i];
            }
            return res;
            
    }
};