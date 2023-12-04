class Solution {
   public:
    bool isvalid(string s) {
        if (s[0] == s[1] && s[1] == s[2]) {
            return 1;
        }
        return 0;
    }
    string largestGoodInteger(string num) {
        vector<char> x;
        for (int i = 0; i < num.size()-2; i++) {
            if (isvalid(num.substr(i, 4))) {
                x.push_back(num[i]);
            }
        }
        if (x.size() == 0) {
            return "";
        }
        string s = "";
        char c = *max_element(x.begin(), x.end());
        s += c;
        s += c;
        s += c;

        return s;
    }
};