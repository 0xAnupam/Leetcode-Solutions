const int N=1e5+1;
int parent[N], rnk[N] , cost[N];

void make(int v ){
    parent[v] = v;
    rnk[v] = 0;
    cost[v]=-1;    
}

int find(int v){
    if(parent[v] != v)
        parent[v] = find(parent[v]);
    return parent[v];
}

void Union(int a, int b ,int v){
    a = find(a);
    b = find(b);
        if(rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        cost[a]&=v;
        cost[a]&=cost[b];   
        if(rnk[a] == rnk[b])
            rnk[a]++;
    
}
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        for(int i=0;i<n;i++)make(i);
            for(auto &i:edges){
                    Union(i[0],i[1],i[2]);
            }
            vector<int> res;
            for(auto &i:query){
                    int a=find(i[0]),b=find(i[1]);
                    if(a==b){
                            if(i[0]==i[1])res.push_back(0);
                            else{res.push_back(cost[a]);}
                    }
                    else{
                            res.push_back(-1);
                    }
            }
            return res;
    }
};