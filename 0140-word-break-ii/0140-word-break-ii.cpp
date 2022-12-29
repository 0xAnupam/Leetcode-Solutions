struct Tries{ 
Tries* arr[26];
bool f=0;
};
void f(vector<string> &res,string temp,Tries* head,Tries* root,string &s,int idx,int n){
       
        if(head==NULL){
                return ;
        }
        if(idx==n){
                
                if(head->f){
                        res.push_back(temp);
                }
                return ;
        }
        if(head->f){
                f(res,temp+' '+s[idx],root->arr[s[idx]-'a'],root,s,idx+1,n);
        }
        if(head->arr[s[idx]-'a']){
                f(res,temp+s[idx],head->arr[s[idx]-'a'],root,s,idx+1,n);
        }
}
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Tries* root=new Tries();
            for(auto &s:wordDict){
                    Tries* head=root;
                    for(auto &i:s){
                            if(head->arr[i-'a']==NULL){
                                    head->arr[i-'a']=new Tries();
                            }
                            head=head->arr[i-'a'];
                           
                    }
                    head->f=1;
            }
            vector<string> res;
            f(res,"",root,root,s,0,s.size());
            return res;
    }
};