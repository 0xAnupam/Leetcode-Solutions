const int N=1e5+1;
int parent[N];
int find(int n){
        if(parent[n]==n){
                return n;
        }
        return parent[n]=find(parent[n]);
}
void Union(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
                if(a>b){
                        swap(a,b);
                        
                }
                parent[b]=a;
        }
}
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        for(int i=0;i<n;i++){
                parent[i]=i;
        }
            for(auto &i:edges){
                    Union(i[0],i[1]);
            }
            map<int,long long> mp;
            for(int i=0;i<n;i++){
                    mp[find(i)]++;
            }
            long long res=0;
            for(auto &i:mp){
                    res+=i.second*(n+0LL-i.second);
            }
            return res/2;
    }
};