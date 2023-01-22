// bool valid(string &s){
//         stack<int> S;
//         for(auto &i:s){
//                 if(i=='('){
//                         S.insert(i);
//                 }
//                 else if(i==')' && S.size() && S.top()=='('){
//                         S.pop();
//                 }
//                 else{
//                         S.insert(i);
//                 }
//         }
//         return S.size()==0;
// }
void f(set<string> &res,string &s,string &temp,int idx,int n,int cur){
     
        if(idx==n){
                if(cur==0){
                        res.insert(temp);
                }
                return ;
        }
        f(res,s,temp,idx+1,n,cur);
        int p=1;
        if(s[idx]==')'){
                p=-1;
        }
        else if(s[idx]!='('){
                p=0;
        }
        if(cur+p>=0){
                temp+=s[idx];
                f(res,s,temp,idx+1,n,cur+p);
                temp.pop_back();
        }
}
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
       set<string> res;
            string S="";
            f(res,s,S,0,s.size(),0);
            vector<string> ans;
            int k=s.size(),n=k;
            for(auto &i:res){
                    k=min((int)(n-i.size()),k);
            }
            for(auto &i:res){
                    if(i.size()==n-k){
                            ans.push_back(i);
                    }
            }
            return ans;
    }
};