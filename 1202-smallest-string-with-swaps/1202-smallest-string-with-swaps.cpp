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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
            for(int i=0;i<n;i++){
                    parent[i]=i;
            }
            for(auto &i:pairs){
                    Union(i[0],i[1]);
            }
            map<int,multiset<char> > mp;
            for(int i=0;i<n;i++){
                    mp[find(i)].insert(s[i]);
            }
            string res="";
            for(int i=0;i<n;i++){
                    int t=find(i);
                    res+=*(mp[t].begin());
                    mp[t].erase(mp[t].begin());
            }
            return res;
    }
};