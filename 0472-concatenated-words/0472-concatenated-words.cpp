struct Tries{ 
Tries* arr[26];
bool f=0;
};
void f(set<string> &res,string temp,Tries* head,Tries* root,string &s,int idx,int n,int k){
       
        if(idx==n){
                if(k==0){
                        return ;
                }
                if(head && head->f){
                        res.insert(temp);
                }
                return ;
        }
        if(head==NULL){
                return ;
        }
        
        if(head->arr[s[idx]-'a']){
                head=head->arr[s[idx]-'a'];
                temp+=s[idx];
                f(res,temp,head,root,s,idx+1,n,k);
                if(head->f==1){
                        f(res,temp,root,root,s,idx+1,n,k+1);
                }
        }
}
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
         Tries* root=new Tries();
            for(auto &s:words){
                    Tries* head=root;
                    for(auto &i:s){
                            if(head->arr[i-'a']==NULL){
                                    head->arr[i-'a']=new Tries();
                            }
                            head=head->arr[i-'a'];
                           
                    }
                    head->f=1;
            }
            set<string> res;
            for(auto &s:words){
            f(res,"",root,root,s,0,s.size(),0);}
            vector<string> ans;
            for(auto &i:res){
                    ans.emplace_back(i);
            }
            return ans;
    }
};