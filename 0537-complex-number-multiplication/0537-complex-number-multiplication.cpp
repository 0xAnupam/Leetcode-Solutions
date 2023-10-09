pair<int,int> Cmplx(string &s){
        int r=0,c=0;
        int n=s.size(),i=0;
        bool a=0,b=0;
        if(s[0]=='-'){
                a=1;
                i++;
        }
        while(s[i]!='+'){
                r*=10;
                r+=(s[i]-'0');
                i++;
        }
        i++;
        if(s[i]=='-'){
                b=1;
                i++;
        }
        while(s[i]!='i'){
                c*=10;
                c+=(s[i]-'0');
                i++;
        }
        if(a){
                r*=-1;
        }
        if(b){
                c*=-1;
        }

        return {r,c};
}
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto a=Cmplx(num1),b=Cmplx(num2);
        int r=a.first*b.first-a.second*b.second;
        int c=a.first*b.second+a.second*b.first;
        string res="";
        res+=to_string(r);
        res+='+';
        res+=to_string(c);
        res+='i';
            return res;
    }
};