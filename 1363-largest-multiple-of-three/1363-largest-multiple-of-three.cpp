string remove_zeroes(string &s){
        reverse(s.begin(),s.end());
        while(s.size()>1 && s[s.size()-1]=='0'){
                s.pop_back();
        }
        reverse(s.begin(),s.end());
        return s;
}
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int p=0,a=0,b=0,c=0;
        vector<int> f(10,0);
            for(auto  &i:digits){
                    p+=(i);
                    f[i]++;
                    if((i)%3==1){
                            a++;
                    }
                    else if((i)%3){
                            b++;
                    }
            }
            if(p%3==0){
                   ;
            }
            else if(p%3==1 && a){
                    int k=1;
                    for(int i=1;i<10;i+=3){
                            
                            if(f[i] && k){
                                    f[i]--;
                                    k--;
                                    break;
                            }
                    }
            }
            else if(p%3==1){
                    int k=2;
                    for(int i=2;i<10;i+=3){
                            while(f[i] && k){
                                    f[i]--;
                                    k--;
                            }
                    }
            }
            else if(p%3==2 && b){
                    int k=1;
                    for(int i=2;i<10;i+=3){
                            
                            if(f[i] && k){
                                    f[i]--;
                                    k--;
                                    
                            }
                    }
            }
            else if(p%3==2){
                     int k=2;
                    for(int i=1;i<10;i+=3){
                            while(f[i] && k){
                                    f[i]--;
                                    k--;
                            }
                    }
            }
            string res="";
                    for(int i=9;i>=0;i--){
                            while(f[i]>0){
                                    f[i]--;
                                    res+=(i+'0');
                            }
                    }
            return remove_zeroes(res);
    }
};