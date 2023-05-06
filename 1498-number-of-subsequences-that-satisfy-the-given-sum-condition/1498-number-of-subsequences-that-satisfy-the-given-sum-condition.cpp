const long long mod=1e9+7;
long long mpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        long long res=0;
        sort(nums.begin(),nums.end());
        int n=nums.size(),i=0;
        while(i<n && 2*nums[i]<=target){
                int p=upper_bound(nums.begin()+i,nums.end(),target-nums[i])-nums.begin();
               // cout<<i<<'\t'<<p<<'\n';
                i++;
                res+=mpow(2,p-i,mod);
                res%=mod;
                
        }    
            return res;
    }
};