class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int res=1,n=nums.size();
            int m=nums[n-1];
            int arr[n];
            arr[n-1]=m;
            for(int i=n-1;i>0;i--){
                    m=min(m,nums[i]);
                    arr[i-1]=m;
            }
            m=nums[0];
            for(int i=0;i<n;i++){
                    m=max(m,nums[i]);
                    if(m<=arr[i]){
                            return i+1;
                    }
            }
            return n;
            
    }
};