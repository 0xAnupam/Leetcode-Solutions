class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s="",t="";
            for(auto &i:word1){
                    s.append(i);
            }
            for(auto &i:word2){
                    t.append(i);
            }
            return s==t;
    }
};