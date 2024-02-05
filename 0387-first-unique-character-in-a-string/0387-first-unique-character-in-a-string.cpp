class Solution {
public:
    int firstUniqChar(string s) {
        int x=0,y=0,n=s.size();
            for(auto &i:s){
                    if((1<<(i-'a'))&x){
                            y|=(1<<(i-'a'));
                    }
                    else{
                            x|=(1<<(i-'a'));
                    }
            }
            for(int i=0;i<n;i++){
                    if(((1<<(s[i]-'a'))&y)==0)return i;
            }
            return -1;
    }
};