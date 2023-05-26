class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
            int n=arr.size();
       vector<pair<int,int>> nums(n);
            int j=0;
            for(auto &i:arr){
                    nums[j]={abs(i-x),i};
                    j++;
            }
            sort(nums.begin(),nums.end());
            vector<int> res(k);
            j=0;
            while(j<k){
                    res[j]=nums[j].second;
                    j++;
            }
            sort(res.begin(),res.end());
            return res;
    }
};