class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int l, int r) {
        long long res=0,n=nums.size();
            vector<int> left(n);
            int p=n;
            for(int  i=n-1;i>=0;i--){
                   if(nums[i]>r){
                           p=i;     
                   }
                   left[i]=p; 
            }
            int cnt=0;
            for(int i=0;i<n;i++){
                    if(nums[i]<l){
                            cnt++;
                    }
                    else if(nums[i]>=l){
                            cnt++;
                            res+=cnt*(left[i]-i);
                            cnt=0; 
                            
                    }
                    else {
                            cnt=0;
                    }
                    
            }
            return res;
    }
};