class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum=0;
        int i=0,j=nums.size()-1,res=nums.size()+1;
            while(i<=j && sum<x){
                    sum+=nums[i++];
            }
            if(j<i){
                    return sum==x ? nums.size():-1;
            }
            i--;
            if(sum==x){
                    res=i+1;
            }
            while(j>=i && j>=0){
                    sum+=nums[j--];
                    while(sum>x && i>=0){
                            sum-=nums[i--];
                    }
                    if(sum==x){
                            res=min(res,i+(int)nums.size()-j);
                            
                    }
            }
            return res==nums.size()+1? -1:res;
            
    }
};