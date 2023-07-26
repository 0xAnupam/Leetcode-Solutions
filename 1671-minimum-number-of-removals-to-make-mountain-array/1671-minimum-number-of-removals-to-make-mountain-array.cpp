int dpl[1001],dpr[1001];
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
       int n=nums.size();
            for(int i=0;i<n;i++){
                    dpl[i]=i;
                    for(int j=0;j<i;j++){
                            if(nums[i]>nums[j]){
                                    dpl[i]=min(dpl[i],(i-j)+dpl[j]-1);
                            }                    
                    }
            }
            int res=1e9;
            for(int i=n-1;i>=0;i--){
                    dpr[i]=(n-1)-i;
                    for(int j=i+1;j<n;j++){
                            if(nums[i]>nums[j]){
                                    dpr[i]=min(dpr[i],(j-i)+dpr[j]-1);
                            }
                    }
                    if(dpl[i]<i && dpr[i]<n-1-i){
                            res=min(res,dpl[i]+dpr[i]);
                    }
            }
            return res;
    }
};