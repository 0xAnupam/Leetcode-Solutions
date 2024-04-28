const int N=2e4+1;
int mp[N];
int f(vector<int>& nums, int k,int n){
        int i=0,j=0,res=0,cnt=0;
        while(i<n){
                while(j<n && cnt<k){
                        cnt+=(mp[nums[j]]==0);
                        mp[nums[j]]++;
                        j++;
                }
                if(cnt==k){
                        res+=(n-j+1);
                }
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                        cnt--;
                }
                i++;
        }
        return res;
}
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
            memset(mp,0,(n+1)*sizeof(int));
            return f(nums,k,n)-f(nums,k+1,n);
    }
};