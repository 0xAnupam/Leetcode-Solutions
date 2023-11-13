class Solution {
public:
    string sortVowels(string &S) {
        string t="";
        multiset<char> s;
        set<char> vow={'a','A','e','E','i','I','o','O','u','U'};    
        for(auto &i:S){
                if(vow.find(i)!=vow.end()){
                        s.insert(i);
                }
        } 
            for(auto &i:S){
                    if(vow.find(i)!=vow.end()){
                        t+=(*s.begin());
                            s.erase(s.begin());
                }
                    else{
                            t+=i;
                    }
            }
            return t;
    }
};