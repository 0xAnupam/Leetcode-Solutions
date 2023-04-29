const int N=301;
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
bool similar(string &s,string &t,int n){
        int cnt=0,i=0;
        while(i<n){
                if(s[i]!=t[i]){
                        if(cnt>1){
                                return 0;
                        }
                        cnt++;
                }
                i++;
        }
        return 1;
}
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
            int n=strs.size();
            int sz=strs[0].size();
            for(int i=0;i<n;i++){
                    make(i);
                    for(int j=i-1;j>=0;j--){
                            if(similar(strs[i],strs[j],sz)){
                                    Union(i,j);
                            }
                    }
            }
            set<int> s;
            for(int i=0;i<n;i++){
                    s.insert(find(i));
            }
            return s.size();
    }
};