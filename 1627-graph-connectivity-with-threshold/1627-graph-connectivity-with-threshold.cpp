const int N=1e4+1;
int par[N];
void make(int n){
        par[n]=n;
}
int find(int n){
        if(par[n]==n){
                return n;
        }
        return par[n]=find(par[n]);
}
void Union(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
                par[b]=a;
        }
}
class Solution {
public:
    vector<bool> areConnected(int n, int k, vector<vector<int>>& queries) {
        int arr[n+1],p[n+1];
            memset(arr,0,sizeof(arr));
            for(int i=1;i<=n;i++){
                    make(i);
            }
            for(int i=k+1;i<=n;i++){
                    if(arr[i]==0){
                            for(int j=2;j*i<=n;j++){
                                    Union(i,i*j);
                            }
                    }
            }
            vector<bool> res;
            for(int i=1;i<=n;i++){
                    p[i]=find(i);
            }
            for(auto &i:queries){
                    if(p[i[0]]==p[i[1]]){
                            res.push_back(1);
                    }
                    else{
                            res.push_back(0);
                    }
            }
            return res;
            
    }
};