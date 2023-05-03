const int N=1e5+100;
int par[N];
void make(int n){
        par[n]=n;
}
int Find(int n){
        if(par[n]==n){
                return n;
        }
        return par[n]=Find(par[n]);
}
void Union(int a,int b){
        a=Find(a);
        b=Find(b);
        if(a!=b){
                 par[b]=a;
        }
}
bool cmp(const vector<int> &a,const vector<int> &b){
        return a[2]<b[2];
}
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
            for(int i=0;i<n;i++){
                    make(i);
            }
            sort(edgeList.begin(),edgeList.end(),cmp);
           
            int j=0;
            for(auto &i:queries){
                    i.push_back(j++);
            }
            sort(queries.begin(),queries.end(),cmp);
            vector<bool> res(j);
            j=0;
            int i=0;
            int N=edgeList.size();
            for(auto &q:queries){
                    while(i<N && edgeList[i][2]<q[2]){
                            Union(edgeList[i][0],edgeList[i][1]);
                            i++;
                    }
                    res[q[3]]=(Find(q[0])==Find(q[1]));
            }
            return res;
        
    }
};