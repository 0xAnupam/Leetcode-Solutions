int res[50];
bool f(int n,int idx,int x){
        
        if(res[idx]!=-1){
                return f(n,idx+1,x);
        }
        if(x==0){
                return 1;
        }
        if(idx==2*n){
                return 1;
        }
        bool flag=0;
        for(int i=n;i>1 && flag==0;i--){
                if((1<<i)&x && idx+i<2*n-1 && res[idx+i]==-1){
                        res[idx]=res[idx+i]=i;
                        flag=f(n,idx+1,(x^(1<<i)));
                        if(flag){
                                return 1;
                        }
                        res[idx]=res[idx+i]=-1;
                        
                }
        }
        res[idx]=1;
        if((1<<1)&x && f(n,idx+1,x^2)){
                return 1;
        }
        res[idx]=-1;
        return 0;
}
class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        memset(res,-1,sizeof(res));
            int x=0;
            for(int i=1;i<=n;i++){
                    x|=(1<<i);
            }
            f(n,0,x);
            vector<int> r;
            for(int i=0;i<2*n-1;i++){
                    r.emplace_back(res[i]);
            }
            return r;
    }
};