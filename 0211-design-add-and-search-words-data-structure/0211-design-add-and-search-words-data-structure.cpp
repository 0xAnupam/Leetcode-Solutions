
class WordDictionary {
public:
    struct Tries{
           int c=0;
           Tries* arr[26];
        };
        Tries* root;
    WordDictionary() {
         root=new Tries();
    }
        bool f(string &s,int idx,int n,Tries* root){
        Tries* head=root;        
        if(head==NULL){
                return 0;
        }        
       
        for(int i=idx;i<n;i++){
                if(s[i]=='.'){
                        bool p=0;
                        
                        for(int j=0;j<26;j++){
                                if(head->arr[j]){
                                        p|=f(s,i+1,n,head->arr[j]);
                                }       
                        }
                        return p;
                }
                else if(head->arr[s[i]-'a']==NULL){
                        return 0;
                }
                head=head->arr[s[i]-'a'];
                
        }
                
        return (head->c)==1;
}
        
    
    void addWord(string word) {
        Tries* head=root;
            for(auto &i:word){
                    if(head->arr[i-'a']==NULL){
                            head->arr[i-'a']=new Tries();
                    }
                    head=head->arr[i-'a'];
                    
            }
            head->c=1;
    }
    
    bool search(string word) {
        return f(word,0,word.size(),root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */