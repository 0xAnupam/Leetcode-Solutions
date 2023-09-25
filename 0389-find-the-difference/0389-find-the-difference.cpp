class Solution {
public:
    char findTheDifference(string s, string t) {
        char c=' ';
            for(auto &i:s){
                    c^=i;
            }
            for(auto &i:t){
                    c^=i;
            }
            return (c-'A'+'a');
            
    }
};