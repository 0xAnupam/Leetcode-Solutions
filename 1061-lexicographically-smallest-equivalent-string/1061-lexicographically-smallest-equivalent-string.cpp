int parent[26];
void Set(int i,int val){
        parent[i]=val;
}
int Find(int n){
        if(parent[n]==n){
                return n;
        }
        return parent[n]=Find(parent[n]);
}
void Union(int a,int b){
        int x=Find(a);
        int y=Find(b);
        if(x>y){
                swap(x,y);
        }
        parent[y]=x;
}
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i=0;i<26;i++){
                Set(i,i);
        }
            int n=s1.size();
            for(int i=0;i<n;i++){
                    Union(s1[i]-'a',s2[i]-'a');
            }
            string res="";
            for(auto &i:baseStr){
                    res+=('a'+Find(i-'a'));
            }
            return res;
    }
};