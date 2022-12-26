class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
            if(n%groupSize){
                    return 0;
            }
            int k=n/groupSize;
            map<int,int> mp;
            for(auto &i:hand){
                    mp[i]++;
            }
            while(k--){
                    auto p=(*mp.begin()).first;
                    for(int i=p;i<p+groupSize;i++){
                            if(mp[i]==0){
                                    return 0;
                            }
                            if(mp[i]==1){
                                    mp.erase(i);
                            }
                            else{
                                    mp[i]--;
                            }
                    }
            }
            return 1;
    }
};