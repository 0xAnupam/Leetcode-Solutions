class Solution {
public:
    string removeDuplicateLetters(string str) {
        vector<bool> vis(26,0);
            stack<char> s;
            vector<int> last(26,-1);
            int n=str.size();
            for(int i=0;i<n;i++){
                    last[str[i]-'a']=i;
            }
            for(int i=0;i<n;i++){
                    
                    if(vis[str[i]-'a']){
                            continue ;
                    }
                    
                    while(s.size() && s.top()>str[i] && last[s.top()-'a']>i){
                            
                            vis[s.top()-'a']=0;
                            s.pop();
                    }
                    s.push(str[i]);
                    vis[str[i]-'a']=1;
            }
            string res="";
            while(s.size()){
                    res+=s.top();
                    s.pop();
            }
            reverse(res.begin(),res.end());
            return res;
    }
};