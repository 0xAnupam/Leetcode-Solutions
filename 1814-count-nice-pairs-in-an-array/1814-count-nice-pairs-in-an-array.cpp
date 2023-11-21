int rev(int n){
        string s=to_string(n);
        reverse(s.begin(),s.end());
        return stoi(s);
}
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        map<int,int> mp;
        int res=0,n=nums.size(),mod=1e9+7;
            for(int i=0;i<n;i++){
                    int x=nums[i]-rev(nums[i]);
                    res+=(mp[x]++);
                    res%=mod;
            }
            return res;
    }
};