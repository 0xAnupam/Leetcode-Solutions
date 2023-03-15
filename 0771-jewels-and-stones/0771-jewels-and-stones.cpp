class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int> mp;
            for(auto &i:jewels){
                    mp[i]=1;
            }
            int res=0;
            for(auto &i:stones){
                    res+=mp[i];
            }
            return res;
    }
};