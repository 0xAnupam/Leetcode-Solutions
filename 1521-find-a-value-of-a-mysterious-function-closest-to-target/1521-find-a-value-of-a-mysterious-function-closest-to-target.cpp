struct SegMentTreeAND {
    private:
    int* Seg_Tree;
    
    vector<int> arr;
    public:
    SegMentTreeAND(vector<int> &arr, int n) {
        this->arr = arr;
        Seg_Tree=new int[4*n];    
        build(0, 0, n);
            
    }
    void build(int x, int l, int r) {
        if (r - l == 1) {
           
            Seg_Tree[x] = arr[l];
            return ;
        }
        int mid = l + (r - l) / 2;
        build(2 * x + 1, l, mid);
        build(2 * x + 2, mid, r);
        Seg_Tree[x] = (Seg_Tree[2 * x + 1] & Seg_Tree[2 * x + 2]);
    }
    int query(int x, int a, int b, int l, int r) {
        if (a >= r || b <= l) {
            return -1;
        }
        else if (a <= l && b >= r) {
            return Seg_Tree[x];
        }
        int mid = l + (r - l) / 2;
        auto left = query(2 * x + 1, a, b, l, mid);
        auto right = query(2 * x + 2, a, b, mid, r);
        return (left & right);
    }
    
};class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int n=arr.size();    
        SegMentTreeAND Tree(arr,n);
            int res=INT_MAX;
            for(int i=0;i<n;i++){
                    int l=i,h=n-1,m;
                    while(l<=h){
                            m=(l+h)/2;
                            if(Tree.query(0,i,m+1,0,n)>target){
                                    l=m+1;
                            }
                            else{
                                    h=m-1;
                            }
                    }
                    res=min(res,abs(target-Tree.query(0,i,l+1,0,n)));
                    if(i!=l){
                            res=min(res,abs(target-Tree.query(0,i,l,0,n)));
                    }
            }
            return res;
    }
};