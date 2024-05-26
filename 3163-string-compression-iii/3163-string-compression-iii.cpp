class Solution {
public:
    string compressedString(string word) {
        string res="";
        int i=0,n=word.size();
        while(i<n){
            int cnt=0;
            char c=word[i];
            while(i<n && cnt<9 && word[i]==c)i++,cnt++;
            res+=(cnt+'0');
            res+=c;
        }
        return res;
    }
};