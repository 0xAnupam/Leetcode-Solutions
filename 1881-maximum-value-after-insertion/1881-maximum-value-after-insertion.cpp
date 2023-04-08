class Solution {
public:
    string maxValue(string n, int x) {
        char a='0'+x;
            int f=1;
            int N=n.size();
            int i=0;
            string res="";
            if(n[i]=='-'){
                    res+='-';
                    i++;
                    while(i<N){
                            if(f && n[i]>a){
                                    res+=a;
                                    f--;
                            }
                            res+=n[i++];
                    }
            }
            while(i<N){
                    if(f && n[i]<a){
                            res+=a;
                            f--;
                    }
                    res+=n[i++];
            }
            if(f){
                    res+=a;
            }
            
            return res;
    }
};