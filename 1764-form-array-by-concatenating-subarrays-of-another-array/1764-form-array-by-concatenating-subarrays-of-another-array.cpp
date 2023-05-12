bool match(vector<int> &pattern,vector<int> &nums,int i,int m){
        int n=pattern.size();
        if(i+n-1>=m){
                return 0;
        }
        int j=i+n-1;
        int p=0,q=n-1;
        while(i<=j){
                if(nums[i]!=pattern[p]){
                        return 0;
                }
                i++;
                p++;
                if(nums[j]!=pattern[q]){
                        return 0;
                }
                j--;
                q--;
        }
        return i>=j;
}
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i=0,j=0,n=groups.size(),m=nums.size();
            while(i<n && j<m){
                    if(match(groups[i],nums,j,m)){
                            j+=groups[i].size();
                            i++;
                            
                    }
                    else{
                            j++;
                    }
                    
            }
            return i==n;
    }
};