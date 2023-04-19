const int N=2e5;
int seg_tree[N];
void build(int l,int r,int x){
        if(r-l==1){
                 seg_tree[x]=1;
                return ;
        }
        int  m=l+(r-l)/2;
        build(l,m,2*x+1);
        build(m,r,2*x+2);
        seg_tree[x]=1;
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
        seg_tree[x]=seg_tree[2*x+1]*seg_tree[2*x+2];
}
int pro(int l,int r,int x,int a,int b){
        if(l>=b || a>=r){
                return 1;
        }
        if(a<=l && r<=b){
                return seg_tree[x];
        }
        int m=l+(r-l)/2;
        return pro(l,m,2*x+1,a,b)*pro(m,r,2*x+2,a,b);
}
int idx;
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        build(0,40001,0);    
        idx=0;
    }
    
    void add(int num) {
        Update(0,40001,idx,num,0);
            idx++;
    }
    
    int getProduct(int k) {
        return pro(0,40001,0,max(0,idx-k),idx);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */