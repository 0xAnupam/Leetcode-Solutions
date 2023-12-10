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
    int help(vector<int>& nums,int idx,unordered_map<int,int>& m){
        if(idx==nums.size())
            return 0;
        int j=m[nums[idx]];
        while(idx<=j){
            j=max(j,m[nums[idx]]);
            idx++;
        }
        return 1+help(nums,j+1,m);
    }
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]=i;
        int res=help(nums,0,m);
        return mpow(2,res-1,1e9+7);
        
    }
};