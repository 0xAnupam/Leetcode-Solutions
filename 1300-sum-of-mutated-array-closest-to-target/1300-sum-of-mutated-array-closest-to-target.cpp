
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
            int n=arr.size();
        vector<int> nums(n);
            int sum=0;
            int diff=1e9+1,res=0;
            for(int i=0;i<n;i++){
                    sum+=arr[i];
                    nums[i]=sum;
            }
            nums.push_back(sum);
            int i=0,q=0;
            while(i<=arr[n-1]){
                    auto p=upper_bound(arr.begin(),arr.end(),i)-arr.begin();
                   
                    int k=nums[p];
                    if(p<n){
                            k-=arr[p];
                    }
                    k+=(n-p)*i;
                    
                    if(abs(target-k)<diff){
                            diff=abs(target-k);
                            res=i;
                    }
                    i++;
            }
            return res;
    }
};