bool window(vector<int> &a,vector<int>&b){
        for(int i=0;i<58;i++){
                if(a[i]>b[i]){
                        return 0;
                }
        }
        return 1;
}
class Solution {
public:
    string minWindow(string &s, string &t) {
            int n=s.size(),m=t.size();
            if(m>n){
                    return "";
            }
        vector<int> f(58,0);
        for(auto &i:t){
                f[i-'A']++;
        }
            vector<int> cur(58,0);
            int i=0;
            while(i<m){
                    cur[s[i++]-'A']++;
            }
            int res=n+1;
            int a=0,b=n+1;
            int j=0;
            while(i<n){
               while(i<n && window(f,cur)==false){
                    cur[s[i++]-'A']++;
                  }
                    while(j<=i && window(f,cur)){
                            if(i-j<=b-a){
                                    a=j;
                                    b=i;
                            }
                            cur[s[j++]-'A']--;
                    }
            }
            for(int i=0;i<58;i++){
                    cur[i]=0;
             }
            string p=s.substr(a,b-a);
            for(auto &i:p){
                    cur[i-'A']++;
            }
            return window(f,cur) ? p:"";
            
    }
};