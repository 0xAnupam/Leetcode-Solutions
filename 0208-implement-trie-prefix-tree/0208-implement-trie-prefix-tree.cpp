struct Tries{ 
int c=0;
Tries* arr[26];
bool f=0;
};
Tries* root;
class Trie {
public:
    Trie() {
       root=new Tries ();
    }
    
    void insert(string word) {
        Tries* head=root;
        for(auto &i:word){
                if(head->arr[i-'a']==NULL){
                        head->arr[i-'a']=new Tries();
                }
                head=head->arr[i-'a'];
                head->c=1;
        }
            head->f=1;
    }
    
    bool search(string word) {
        Tries* head=root;
        for(auto &i:word){
                if(head->arr[i-'a']==NULL){
                        return 0;
                }
                head=head->arr[i-'a'];
                
        }
            return head->f;
    }
    
    bool startsWith(string prefix) {
        Tries* head=root;
        for(auto &i:prefix){
                if(head->arr[i-'a']==NULL){
                        return 0;
                }
                head=head->arr[i-'a'];
               
        }
            return head->c;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */