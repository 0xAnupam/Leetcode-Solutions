class Solution {
public:
        vector<int> frequency(string &s){
    vector<int> f(26,0);
     for(auto &i:s)
     {
             f[i-'a']++;
     }return f; 
        }
    bool there(vector<int> &f,vector<int> &c)
    {
        for(int i=0;i<26;i++)
        {
                if(c[i]>f[i]){return 0;}
        }
         for(int i=0;i<26;i++)
         {  f[i]-=c[i];
                 
         }
            return 1;
            
    }
    
    string originalDigits(string s) {
     vector<int> f=frequency(s);
        vector<string> x ={"zero","one","two","three","four","five","six","seven","eight","nine"};
 vector<vector<int>> c;
            for(auto &i:x){
                    c.push_back(frequency(i));
            }
            string res="";
            while(f['z'-'a']){
                    res+='0';
                    for(auto &j:x[0]){
                            f[j-'a']--;
                    }
            }
            while(f['w'-'a']){
                    res+='2';
                    for(auto &j:x[2]){
                            f[j-'a']--;
                    }
            }
            while(f['u'-'a'] && f['f'-'a']){
                    res+='4';
                    for(auto &j:x[4]){
                            f[j-'a']--;
                    }
            }
            while( f['f'-'a']){
                    res+='5';
                    for(auto &j:x[5]){
                            f[j-'a']--;
                    }
            }
            while(f['x'-'a']){
                    res+='6';
                    for(auto &j:x[6]){
                            f[j-'a']--;
                    }
            }
            while(f['v'-'a']){
                    res+='7';
                    for(auto &j:x[7]){
                            f[j-'a']--;
                    }
            }
            while(f['o'-'a']){
                    res+='1';
                    for(auto &j:x[1]){
                            f[j-'a']--;
                    }
            }
            bool flag=1;
            while(flag){flag=0;
            for(int i=0;i<10;i++)
            {  
             if(there(f,c[i]))
             {
                     flag=1;res+=i-0+'0';
                     
             }
                   
            }
            }
            sort(res.begin(),res.end());
        return res;
    }
};