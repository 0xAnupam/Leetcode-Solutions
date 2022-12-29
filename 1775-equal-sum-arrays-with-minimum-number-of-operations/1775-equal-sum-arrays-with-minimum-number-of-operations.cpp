int f(vector<int>& nums1, vector<int>& nums2,int sum){
        sort(nums1.begin(),nums1.end());
        sort(nums2.rbegin(),nums2.rend());
        int res=0,i=0,j=0,n=nums1.size(),m=nums2.size();
        while(sum>0 && i<n && j<m){
                if((6-nums1[i])>nums2[j]-1){
                        sum-=(6-nums1[i++]);
                }
                else{
                        sum-=(nums2[j++]-1);
                }
                res++;
        }
        while(sum>0 && i<n){
                res++;
                sum-=(6-nums1[i++]);
        }
        while(sum>0 && j<m){
                res++;
                sum-=(nums2[j++]-1);
        }
        return sum>0? -1:res;
}
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
       
        int res=0;
            for(auto &i:nums1){
                    res+=i;
            }
            for(auto &i:nums2){
                    res-=i;
            }
            if(res==0){
                    return 0;
            }
            if(res>0){
                    return f(nums2,nums1,res);
            }
            return f(nums1,nums2,-res);
    }
};