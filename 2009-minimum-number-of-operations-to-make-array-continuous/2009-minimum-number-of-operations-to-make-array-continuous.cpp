class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
            int i=0,n=nums.size();
            vector<int> arr;
            while(i<n){
                    int p=nums[i];
                    while(i<n && nums[i]==p){
                            i++;
                    }
                    arr.emplace_back(p);
            }
            long res=n,j=0;
            int N=arr.size();
            for(int i=0;i<N;i++){
                    while(j<N && arr[j]-arr[i]<n){
                            j++;
                    }
                    res=min(res,n-(j-i));
            }
            return res;
    }
};