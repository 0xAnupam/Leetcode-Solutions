class Solution {
public:
    int numSteps(string s) {
        int res=0,i=s.size()-1,cnt=0;
            while(i>0){
                    if(s[i]-'0'+cnt==1){
                            res+=2;
                            cnt=1;
                    }
                    else if(s[i]-'0'+cnt==0){
                            res++;
                            cnt=0;
                    }
                    else{
                            res++;
                            cnt=1;
                    }
                    i--;
            }
            return res+cnt;
    }
};