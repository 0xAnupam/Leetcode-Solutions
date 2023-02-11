const int N=6e5+1;
int seg_tree[N];
void Update(int l,int r,int idx,int val,int x){
        if(r-l==1){
                seg_tree[x]=val;
                return ;
        }
        
        int m=l+(r-l)/2;
        if(idx<m){
                Update(l,m,idx,val,2*x+1);
        }
        else{
                Update(m,r,idx,val,2*x+2);
        }
        seg_tree[x]=max(seg_tree[2*x+1],seg_tree[2*x+2]);
}
int maxi(int l,int r,int x,int a,int b){
        if(l>=b || a>=r){
                return 0;
        }
        if(a<=l && r<=b){
                return seg_tree[x];
        }
        int m=l+(r-l)/2;
        return max(maxi(l,m,2*x+1,a,b),maxi(m,r,2*x+2,a,b));
}
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n=nums.size(),h=1e5+1,res=1;
            memset(seg_tree,0,sizeof(seg_tree));
            for(int i=n-1;i>=0;i--){
                    int p=maxi(0,h,0,nums[i]+1,nums[i]+k+1);
                    res=max(res,1+p);
                    int m=max(1+p,maxi(0,h,0,nums[i],nums[i]+1));
                    Update(0,h,nums[i],m,0);
            }
            return res;
    }
};