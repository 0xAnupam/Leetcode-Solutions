const int N=3e6;
int seg_tree[N];
int seg[N];
void build_min(vector<int> &nums,int l,int r,int x){
        if(r-l==1){
                 seg_tree[x]=nums[l];
                return ;
        }
        int  m=l+(r-l)/2;
        build_min(nums,l,m,2*x+1);
        build_min(nums,m,r,2*x+2);
        seg_tree[x]=min(seg_tree[2*x+1],seg_tree[2*x+2]);
}

int mini(int l,int r,int x,int a,int b){
        if(l>=b || a>=r){
                return 1e9+1;
        }
        if(a<=l && r<=b){
                return seg_tree[x];
        }
        int m=l+(r-l)/2;
        return min(mini(l,m,2*x+1,a,b),mini(m,r,2*x+2,a,b));
}
void build_max(vector<int> &nums,int l,int r,int x){
        if(r-l==1){
                 seg[x]=nums[l];
                return ;
        }
        int  m=l+(r-l)/2;
        build_max(nums,l,m,2*x+1);
        build_max(nums,m,r,2*x+2);
        seg[x]=max(seg[2*x+1],seg[2*x+2]);
}

int maxi(int l,int r,int x,int a,int b){
        if(l>=b || a>=r){
                return 0;
        }
        if(a<=l && r<=b){
                return seg[x];
        }
        int m=l+(r-l)/2;
        return max(maxi(l,m,2*x+1,a,b),maxi(m,r,2*x+2,a,b));
}
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int n=nums.size();
        build_max(nums,0,n,0);
        build_min(nums,0,n,0);
        int res=0;
        int i=0;
            while(i<n){
                int l=i,h=n-1,m;
                while(l<=h){
                        m=(l+h)/2;
                        int ma=maxi(0,n,0,i,m+1);
                        int mi=mini(0,n,0,i,m+1);
                        if(ma-mi>limit){
                                h=m-1;
                        }
                        else{
                                l=m+1;
                        }
                        
                }
                res=max(res,l-i);
                int p=nums[i],cnt=0;
                while(i<n && nums[i]==p){
                      
                        i++;
                        cnt++;
                }
               
               
        }   
            return res;
    }
};