void  f(int* fre,vector<int> &part,string &s,int idx,int n){
        if(idx==n){
                return ;
        }
        int en_idx=fre[s[idx]-'a'];
        for(int i=idx;i<=en_idx;i++){
                en_idx=max(en_idx,fre[s[i]-'a']);
        }
        en_idx++;
        part.push_back(en_idx-idx);
        f(fre,part,s,en_idx,n);
}
class Solution {
public:
    vector<int> partitionLabels(string s) {
            int fre[26];
            int n=s.size();
            for(int i=0;i<n;i++){
                    fre[s[i]-'a']=i;
            }
            vector<int> res;
            f(fre,res,s,0,n);
            return res;
        
    }
};