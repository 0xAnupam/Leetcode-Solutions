class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> nums=arr;
        sort(nums.begin(),nums.end());
        int i=0,res=0,n=nums.size();
        long long a=0,b=0;
        while(i<n){
            a+=nums[i];
            b+=arr[i++];
            if(a==b){
                res++;
            }
        }
        return res;
    }
};