class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int o=0,e=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
                if(i&1){
                        o+=nums[i];
                }
                else{
                    e+=nums[i];    
                }
        }    
        int res=0;
        int a=0,b=0;
        for(int i=0;i<n;i++){
                if(i&1){
                        o-=nums[i];
                }
                else{
                        e-=nums[i];
                }
                res+=((a+e)==(b+o));
                if(i&1){
                        a+=nums[i];
                }
                else{
                        b+=nums[i];
                }
        }    
            return res;
    }
};