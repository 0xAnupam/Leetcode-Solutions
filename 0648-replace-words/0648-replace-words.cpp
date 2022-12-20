struct Tries{ 
Tries* arr[26];
int  f=0;
};
string F(string &p,Tries* head){
        int i=0,n=p.size();
        while(i<n){
                if(head->arr[p[i]-'a']==NULL){
                        return p;
                }
                head=head->arr[p[i]-'a'];
                if(head->f){
                        return p.substr(0,i+1);
                }
                i++;
        }
        return p;
}
class Solution {
public:
        
    string replaceWords(vector<string>& dictionary, string sentence) {
        Tries* root=new Tries();
            for(auto &i:dictionary){
                    Tries* head=root;
                    for(auto &j:i){
                            if(head->arr[j-'a']==NULL){
                                    head->arr[j-'a']=new Tries();
                            }
                            head=head->arr[j-'a'];
                    }
                    head->f=1;
            }
            string res="",t="";
            for(auto &i:sentence){
                    if(i==' '){
                            res+=F(t,root);
                            res+=' ';
                            t="";
                    }
                    else{
                            
                            t+=i;
                    }
                    
            }
            res+=F(t,root);
            return res;
            
    }
};