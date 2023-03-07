bool f(vector<int> &nums,int N,int n ,long long mid){
        int ele=0,carry=0,i=0;
        while(i<n){
                long long p=carry;
                if(p>=mid){
                        p=0;
                }
                while(i<n && p<mid){
                        p+=nums[i++];
                        carry=p-mid;
                }
                if(p>=mid){
                        N--;
                        if(N<=0){
                               return 1;
                        }
                       
                }
                else{
                        return 0;
                }
        }
        return 0;
}
class Solution {
public:
    long long maxRunTime(int n, vector<int>& nums) {
        sort(nums.begin(),nums.end());
       
            int N=nums.size();
            long long l=0,h=1e15,m;
            while(l<=h)
            {
                m=l+(h-l)/2;
                    
                            if(f(nums,n,N,m)){
                                    l=m+1;
                            }
                            else{
                                    h=m-1;
                            }
                    
            }
           return h;
    }
};