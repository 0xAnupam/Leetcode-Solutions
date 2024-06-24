class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> bias(n+1,0);
        int sum=0,res=0;
        for(int i=0;i<n;i++){
            sum+=bias[i];
            nums[i]=(nums[i]+sum)&1;
            if(nums[i]==0){
                if(i>n-k)return -1;
                res++;
                sum++;
                bias[i+k]--;
            }
        }
        return res;
    }
};