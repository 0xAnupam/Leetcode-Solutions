class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> mp;
            long long res=0;
            for(auto &i:rectangles){
                    int hcf=__gcd(i[0],i[1]);
                    i[0]/=hcf;
                    i[1]/=hcf;
                    res+=mp[{i[0],i[1]}]++;
            }
            return res;
    }
};