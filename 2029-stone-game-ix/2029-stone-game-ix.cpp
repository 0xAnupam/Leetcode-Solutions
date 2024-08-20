
bool winner(int a,int b,int c , int strategy ){
    bool alice=1;
    int j=0,sum=0;
    while(1){
        int x=sum;
        if(strategy){
            x=strategy;
            strategy=0;
        }
        else{
            x=sum;
        }
        if(max({a,b,c})==0)return 0;
        if(x==2){
            if(b==0 && c==0 ){
                return !alice;
            }
            if(b){
                sum+=2;
                sum%=3;
                b--;
                j++;
            }
            else{
                c--;
            }
        }else{
            
            if(a==0 && c==0){
                return !alice;
            }
            if(a){
                sum++;
                sum%=3;
                a--;
                j++;
            }
            else{
                c--;
            }
        }
        j%=3;
        alice=!alice;
    }
    return false;
}
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int a=0,b=0,c=0;
        for(auto &i:stones){
            i%=3;
            c+=(i==0);
            a+=(i==1);
            b+=(i==2);
        }
        bool ok=0;
        if(a)ok|=winner(a,b,c,1);
        if(b)ok|=winner(a,b,c,2);
        return ok;
    }
};