bool helper(vector<int>& nums1, vector<int>& nums2,int k,int mid){
        auto a=upper_bound(nums1.begin(),nums1.end(),mid)-nums1.begin();
        auto b=upper_bound(nums2.begin(),nums2.end(),mid)-nums2.begin();
        return a+b<=k;
        
}
int f(vector<int>& nums1, vector<int>& nums2,int k){
        int n=nums1.size();
        int m=nums2.size();       
        int l=-1e6,h=1e6,mid;
            while(l<=h){
                    mid=(l+h)/2;
                    if(helper(nums1,nums2,k,mid)){
                            l=mid+1;
                    }
                    else{
                            h=mid-1;
                    }
            }
        return l;
}
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        double a=f(nums1,nums2,(n+m)/2);
            if((n+m)&1){
                    return a;
            }
          
        a+= f(nums1,nums2,(n+m)/2-1);
        a/=2.00;
            
            return a;
    }
};