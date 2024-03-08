int arr[101];
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        memset(arr,0,sizeof(arr));
            for(auto &i:nums)arr[i]++;
            int res=0,cnt=0;
            for(int i=1;i<=100;i++){
                    if(arr[i]>cnt)cnt=arr[i],res=1;
                    else if(arr[i]==cnt)res++;
            }
            return res*cnt;
    }
};