class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
            int res=0,l=0,h=piles.size()-1;
            while(l<h){
                    h--;
                    res+=piles[h--];
                    l++;
            }
            return res;
    }
};