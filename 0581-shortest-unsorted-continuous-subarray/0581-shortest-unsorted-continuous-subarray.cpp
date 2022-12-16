class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> l(n,0);
            int mini=nums[n-1],maxi=nums[0];
            for(int i=0;i<n;i++){
                    maxi=max(maxi,nums[i]);    
                    if(maxi>nums[i]){
                            l[i]=1;
                    }
            }
            for(int i=n-1;i>=0;i--){
                    mini=min(mini,nums[i]);
                    if(mini<nums[i]){
                            l[i]=1;
                    }
            }
            int stn=n,ed=-1;
            for(int i=0;i<n;i++){
                    if(l[i]){
                            stn=min(stn,i);
                            ed=i;
                    }
            }
            if(stn==n){
                    return 0;
            }
            return ed-stn+1;
            
    }
};