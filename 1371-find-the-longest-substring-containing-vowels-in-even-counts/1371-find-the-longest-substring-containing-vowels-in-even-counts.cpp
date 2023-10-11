class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<int,int> dp;
            dp[0]=-1;
            int a=0,e=0,i=0,o=0,u=0,n=s.size(),res=0;
            for(int c=0;c<n;c++){
                    if(s[c]=='a'){
                            a++;
                            a&=1;
                    }
                    else if(s[c]=='e'){
                            e++;
                            e&=1;
                    }
                    else if(s[c]=='i'){
                            i++;
                            i&=1;
                    }
                    else if(s[c]=='o'){
                            o++;
                            o&=1;
                    }
                    else if(s[c]=='u'){
                            u++;
                            u&=1;
                    }
                    int X=((1<<0)*a)+((1<<1)*e)+((1<<2)*i)+((1<<3)*o)+((1<<4)*u);
                    if(dp.find(X)==dp.end()){
                            dp[X]=c;
                    }
                    else{  
                            res=max(res,c-dp[X]);
                    }
            }
            return res;
    }
};