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
        int l=0,r=nums.size()-1,n=nums.size();
            while(l<n && 2*nums[l]<=target){
                    while(r>l && nums[l]+nums[r]>target){
                            r--;
                    }
                    res+=(mpow(2,r-l,mod));
                    res%=mod;
                    l++;
            }
            return res;
    }
};