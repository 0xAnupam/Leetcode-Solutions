bool f(int l,int r,int k,vector<vector<int>> &fre){
        if((r-l+1)&1){
                k++;
        }
        int p=0;
        if(l==0){
                for(int i=0;i<26;i++){
                        p+=(fre[r][i]&1);
                }
                
        }
        else{
             for(int i=0;i<26;i++){
                        p+=((fre[r][i]-fre[l-1][i])&1);
                }   
        }
        p=(p+1)/2;
        return k>=p;
}
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
            int n=s.size();
        vector<vector<int>> fre;
            vector<int> l(26,0);
            for(auto &i:s){
                    l[i-'a']++;
                    fre.emplace_back(l);
            }
            vector<bool> res;
            for(auto &i:queries){
                    res.push_back(f(i[0],i[1],i[2],fre));
            }
            return res;
            
    }
};