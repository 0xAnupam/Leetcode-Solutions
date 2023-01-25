class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int res=-1;
            int i=0,j=0,n=nums1.size(),m=nums2.size();
            while(i<n && j<m){
                    while(i<n && nums1[i]<nums2[j]){
                            i++;
                    }
                    if(i<n && nums1[i]==nums2[j]){
                            return nums1[i];
                    }
                    while(j<m && nums1[i]>nums2[j]){
                            j++;
                    }
                    if(i<n && j<m && nums1[i]==nums2[j]){
                            return nums1[i];
                    }
            }
            return -1;
    }
};