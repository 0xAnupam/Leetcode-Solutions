struct Tries{ 
Tries* arr[26];
int  f=0;
};
Tries* root;
bool F(string &s,int idx,int n,int k,Tries* head){
        if(head==NULL){
                return 0;
        }
        if(idx>=n){
                return k==0 && head->f==1;
        }
        bool p=0;
        
                if(k){     
                    for(int j=0;j<26;j++){
                          if((j!= (s[idx]-'a')) && head->arr[j]){
                                  p|=F(s,idx+1,n,0,head->arr[j]);
                                 }
                      }
                }
                if(head->arr[s[idx]-'a']){
                            p|=F(s,idx+1,n,k,head->arr[s[idx]-'a']);
                   }
        return p;
                
}
class MagicDictionary {
public:
        
    MagicDictionary() {
        root=new Tries();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto &s:dictionary){
                Tries* head=root;
                for(auto &i:s){
                        if(head->arr[i-'a']==NULL){
                                head->arr[i-'a']=new Tries();
                        }
                        head=head->arr[i-'a'];
                }
                head->f=1;
        }
    }
    
    bool search(string searchWord) {
        return F(searchWord,0,searchWord.size(),1,root);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */