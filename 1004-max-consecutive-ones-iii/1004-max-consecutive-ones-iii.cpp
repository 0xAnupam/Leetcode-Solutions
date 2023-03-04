class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,n=nums.size();
            vector<int> arr(n);
            int sum=0;
            for(int i=0;i<n;i++){
                    sum+=(1-nums[i]);
                    arr[i]=sum;
            }
            int m,res=0;
            sum=0;
            while(i<n){
                    auto l=upper_bound(arr.begin()+i,arr.end(),sum+k)-arr.begin();
                    
                    res=max(res,(int)l-i);
                   
                    sum+=(1-nums[i++]);
                    
                    
                    
            }
            return res;
    }
};