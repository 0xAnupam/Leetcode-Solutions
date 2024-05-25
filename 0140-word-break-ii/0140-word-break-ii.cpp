struct Tries{ 
Tries* arr[26];
bool f=0;
};
void f(vector<string> &res,string &temp,Tries* head,Tries* root,string &s,int idx,int n){
       
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
                temp+=' ';
                temp+=s[idx];
                f(res,temp,root->arr[s[idx]-'a'],root,s,idx+1,n);
                temp.pop_back();
                temp.pop_back();
        }
        if(head->arr[s[idx]-'a']){
                temp+=s[idx];
                f(res,temp,head->arr[s[idx]-'a'],root,s,idx+1,n);
                temp.pop_back();
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
            string r="";
            vector<string> res;
            f(res,r,root,root,s,0,s.size());
            return res;
    }
};