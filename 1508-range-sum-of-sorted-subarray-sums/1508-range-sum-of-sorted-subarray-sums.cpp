const long long mod=1e9+7;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> arr;
            for(int i=0;i<n;i++){
                    long long sum=0;
                    for(int j=i;j<n;j++){
                            sum+=nums[j];
                            arr.emplace_back(sum);
                    }
            }
            sort(arr.begin(),arr.end());
            long long res=0;
            for(int i=left-1;i<right;i++){
                    res+=(arr[i]);
                
            }
            res%=mod;
            return res;
    }
};