map<int,int>  Seg_Tree;
map<int,int> lazy;
const int N=1e8+1;
void propagate(int x,int l,int r){
        if(lazy[x]){
                if(r-l>1){
                    lazy[2*x+1]=max(lazy[x],lazy[2*x+1]);
                    lazy[2*x+2]=max(lazy[x],lazy[2*x+2]);
                }
                Seg_Tree[x]=max(Seg_Tree[x],lazy[x]);
                lazy[x]=0;
     }
}

void update(int x,int a,int b,int l,int r,int val){
     propagate(x,l,r);
     if(a>=r || b<=l){
        return ;
     } 
     else if(a<=l && b>=r){
        lazy[x]=val;
        propagate(x,l,r);
        return ;
     }
    int m=(l+r)/2;
    update(2*x+1,a,b,l,m,val);
    update(2*x+2,a,b,m,r,val);
    Seg_Tree[x]=max({Seg_Tree[2*x+1],Seg_Tree[2*x+2],Seg_Tree[x]});    
}
int query(int x,int a,int b,int l,int r){
     propagate(x,l,r);
    if(a>=r || b<=l){
        return 0;
    }
    else if(a<=l && b>=r){
        return Seg_Tree[x];
    }
    int mid=l+(r-l)/2;
    auto left=query(2*x+1,a,b,l,mid);
    auto right=query(2*x+2,a,b,mid,r);
    return max(left,right);
}
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
            Seg_Tree.clear();
            lazy.clear();
        int q=positions.size();
            vector<int> res(q);
            int t=0;
            for(int i=0;i<q;i++){
                    int m=positions[i][1]+query(0,positions[i][0]+1,positions[i][0]+positions[i][1]+(positions[i][1]==1),0,N);
                    t=max(t,m);
                    res[i]=t;
                    update(0,positions[i][0],positions[i][0]+positions[i][1]+1,0,N,m);
                   
            }
            
            return res;
    }
};