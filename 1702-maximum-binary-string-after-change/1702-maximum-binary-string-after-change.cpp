class Solution {
public:
    string maximumBinaryString(string binary) {
        set<int> s;
            int i=0,n=binary.size();
            while(i<n){
                    if(binary[i]=='0'){
                            s.insert(i);
                    }
                    i++;
            }
            string res="";
            vector<int> vis(n,0);
            i=0;
            while(i<n){
                    while(i<n && vis[i]){
                            i++;
                    }
                    if(i<n){
                            if(binary[i]=='1'){
                                    res+='1';
                                    vis[i]=1;
                            }
                            else{   s.erase(i);    
                                    if(s.size()){
                                            auto it=*s.begin();
                                            vis[it]=1;
                                            res+='1';
                                            s.erase(it);
                                    }
                                    else{
                                            res+='0';
                                            vis[i]=1;
                                    }
                            }
                    }
            }
            return res;
            
    }
};