const int N=2e5;
int seg_tree[N];
void build(vector<int>&nums,int l,int r,int x){
        if(r-l==1){
                 seg_tree[x]=nums[l];
                return ;
        }
        int  m=l+(r-l)/2;
        build(nums,l,m,2*x+1);
        build(nums,m,r,2*x+2);
        seg_tree[x]=seg_tree[2*x+1]+seg_tree[2*x+2];
}
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
        seg_tree[x]=seg_tree[2*x+1]+seg_tree[2*x+2];
}
int sum(int l,int r,int x,int a,int b){
        if(l>=b || a>=r){
                return 0;
        }
        if(a<=l && r<=b){
                return seg_tree[x];
        }
        int m=l+(r-l)/2;
        return sum(l,m,2*x+1,a,b)+sum(m,r,2*x+2,a,b);
}
int n;
class NumArray {
public:
    NumArray(vector<int>& nums) {
        memset(seg_tree,0,sizeof(seg_tree));
            n=nums.size();
            build(nums,0,n,0);
    }
    
    void update(int index, int val) {
            Update(0,n,index,val,0);
        
    }
    
    int sumRange(int left, int right) {
        return sum(0,n,0,left,right+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */