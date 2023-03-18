void f(set<string> &res,string &t,string &s,int idx,int n){
        if(idx==n){
                res.insert(t);
                return ;
        }
        f(res,t,s,idx+1,n);
        t+=s[idx];
        f(res,t,s,idx+1,n);
        t.pop_back();
}
class Solution {
public:
    int numTilePossibilities(string tiles) {
        string t="";
            int fact[8];
            fact[0]=1;
            for(int i=1;i<=7;i++){
                    fact[i]=fact[i-1]*i;
            }
            set<string> st;
            sort(tiles.begin(),tiles.end());
            int n=tiles.size();    
            f(st,t,tiles,0,n);
            while(next_permutation(tiles.begin(),tiles.end())){
                  f(st,t,tiles,0,n);
            }
            int res=st.size();
            return res-1;
           
    }
};