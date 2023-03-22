class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res="";
            bool f=1;
            while(a >0 && b>0){
                    if(a-b>1 && f){
                            res+="aab";
                            a-=2;
                            b--;
                            f=1;
                    }
                    else if(b-a>1){
                            res+="bba";
                            b-=2;
                            a--;
                            f=1;
                    }
                    else if(b>=a){
                            res+='a';
                            a--;
                            f=0;
                    }
                    else{
                            res+='b';
                            b--;
                            f=1;
                    }
            }
            while(b){
                    res+='b';
                    b--;
            }
            while(a){
                    res+='a';
                    a--;
            }
            return res;
    }
};