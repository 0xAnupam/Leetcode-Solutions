bool pos(vector<int>&nums,int mid){
        long long p=mid,sum=0;
        for(auto &i:nums){
                sum+=i;
                if(sum>p){
                        return 0;
                }
                p+=mid;
        }
        return 1;
}
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int l=nums[0],h=1e9,m;
            while(l<=h){
                    m=l+(h-l)/2;
                    if(pos(nums,m)){
                            h=m-1;
                    }
                    else{
                            l=m+1;
                    }
            }
            return l;
    }
};