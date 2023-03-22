class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
            int i=0;
            int res=0;
            sort(nums.begin(),nums.end());
            while(i<n){
                   int j=i+1;
                    while(j<n){
                         auto it=lower_bound(nums.begin()+j,nums.end(),nums[i]+nums[j])-nums.begin();
                            if(it>j){
                                    res+=(it-j++-1);
                            }    
                            else{
                                    j=n;
                            }
                    }
                    i++;
            }
            return res;
    }
};