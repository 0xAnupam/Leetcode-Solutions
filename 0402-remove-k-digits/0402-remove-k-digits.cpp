class Solution {
public:
    string removeKdigits(string num, int k) {
           stack<int> s;
            for(auto &i:num){
                    
                    while(s.size() && s.top()>i && k){
                            s.pop();
                            k--;
                    }
                    
                        s.push(i);
                    
            }
            while(s.size() && k--){
                    s.pop();
            }
            string res="";
            while(s.size()){
                    res+=s.top();
                    s.pop();
            }
            if(res==""){
                    return "0";
            }
            reverse(res.begin(),res.end());
           
            int i=0;
            while(i<res.size() && res[i]=='0'){
                    i++;
            }
            res=res.substr(i,res.size()-i);
            if(res==""){
                    return "0";
            }
            return res;
            
    }
};