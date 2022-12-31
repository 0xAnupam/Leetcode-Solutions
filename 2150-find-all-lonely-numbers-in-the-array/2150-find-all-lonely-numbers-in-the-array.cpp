
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
            int N=*max_element(nums.begin(),nums.end());
        vector<int> arr(N+2,0),res;
            for(auto &i:nums){
                    arr[i]++;
            }
            if(arr[0]==1 && arr[1]==0){
                    res.push_back(0);
            }
            for(int i=1;i<=N;i++){
                    if(arr[i]==1 && arr[i-1]==0 && arr[i+1]==0){
                            res.push_back(i);
                    }
            }
            return res;
    }
};