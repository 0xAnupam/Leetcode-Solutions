class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
            for(int i=1;i<n;i++){
                    nums[i]+=nums[i-1];
            }
            int res=0,mod=1e9+7;
            for(int i=0;i<n-1;i++){
                    int mini=lower_bound(nums.begin()+i+1,nums.end(),2*nums[i])-nums.begin();
                    int l=mini,h=n-1,m;
                    while(l<=h){
                            m=(l+h)/2;
                            if(nums[n-1]-nums[m]>=nums[m]-nums[i]){
                                    l=m+1;
                            }
                            else{
                                    h=m-1;
                            }
                    }if(nums[n-1]==0)l--;
                    res+=max(0,l-mini);
                    res%=mod;
            }
            return res;
    }
};