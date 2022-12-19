struct Tries{
   int c=0;
   Tries* arr[26];
 };
Tries* root;
  
class MapSum {
public:
      map<string,int> m;
     MapSum() {
        root=new Tries();
    }
    void insert(string key, int val) {
        Tries* head=root;
            int j=m[key];
            if(j>0){
                    j=val-j;
            }
            else{
                    j=val;
            }
            
            for(auto &i:key){
                    if(head->arr[i-'a']==NULL){
                            head->arr[i-'a']=new Tries();
                    }
                    head->arr[i-'a']->c+=j;
                    head=head->arr[i-'a'];
            }
            m[key]=val;
    }
    
    int sum(string prefix) {
        int res=0;
            Tries* head=root;
            for(auto &i:prefix){
                    if(head->arr[i-'a']==NULL){
                            return 0;
                    }
                    head=head->arr[i-'a'];
                    res=head->c;
                   
            }
            return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */