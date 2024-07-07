void f(vector<string> &res,string &s, int n,int prev){
    if(n==0){
        res.emplace_back(s);
        return ;
    }
    s+='1';
    f(res,s,n-1,1);
    s.pop_back();
    if(prev==1){
        s+='0';
        f(res,s,n-1,0);
        s.pop_back();
    }
}
class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> res;
        string s="";
        f(res,s,n,1);
        return res;
    }
};