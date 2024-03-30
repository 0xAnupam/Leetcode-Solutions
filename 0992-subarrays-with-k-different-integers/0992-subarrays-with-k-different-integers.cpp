int f(vector<int>& nums, int k,int n){
        int i=0,j=0,res=0;
        map<int,int> mp;
        while(i<n){
                while(j<n && (int)mp.size()<k){
                        mp[nums[j]]++;
                        j++;
                }
                if(mp.size()==k){
                        res+=(n-j+1);
                }
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                        mp.erase(nums[i]);
                }
                i++;
        }
        return res;
}
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
            return f(nums,k,n)-f(nums,k+1,n);
    }
};