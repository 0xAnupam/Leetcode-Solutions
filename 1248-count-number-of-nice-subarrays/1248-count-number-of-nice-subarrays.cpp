class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> arr(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                sum++;
            }
            arr[i]=sum;
        }
        long long res=0;
       
        int p=upper_bound(arr.begin(),arr.end(),k)-arr.begin();
        int q=lower_bound(arr.begin(),arr.end(),k)-arr.begin();
        res+=(p-q);
        for(auto &i:arr){
            int p=upper_bound(arr.begin(),arr.end(),i+k)-arr.begin();
            int q=lower_bound(arr.begin(),arr.end(),i+k)-arr.begin();
            res+=(p-q);
            if(q==n){
                return res;
            }
        }
        return res;
    }
};