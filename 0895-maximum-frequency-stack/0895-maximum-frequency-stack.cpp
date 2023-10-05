class FreqStack {
public:
    set<vector<int>> s;
    map<int,int> mp;
    map<int,stack<int>> st;    
    int op;    
    FreqStack() {
            s.clear();
            mp.clear();
            st.clear();
            op=0;
    }
    
    void push(int val) {
            op++;
            
            
        if(st[val].size()==0){
                mp[val]++;
              
                s.insert({1,op,val});
        }
            else{
                    int fre=mp[val];
                    vector<int> tmp={fre,st[val].top(),val};
                    auto it=s.lower_bound(tmp);
                    if(it!=s.end()){
                            s.erase(it);
                    }
                    mp[val]++;
                    s.insert({mp[val],op,val});
                   
            }
             st[val].push(op);
    }
    
    int pop() {
        auto it=*s.rbegin();
            s.erase(it);
            st[it[2]].pop();
            mp[it[2]]--;   
            if(it[0]>1){
                    it[0]--;
                    it[1]=st[it[2]].top();
                    s.insert(it);
            }
            
            return it[2];
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */