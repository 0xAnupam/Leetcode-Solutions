class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
            
            int n=deck.size();
        vector<int> res(n);
            deque<int> s;
            for(int i=0;i<n;i++){
                    s.push_back(i);
            }
            int i=0;
            while(s.size()>1){
                    auto p=s.front();
                    s.pop_front();
                    
                    res[p]=deck[i++];
                    p=s.front();
                    s.pop_front();
                    s.push_back(p);
                    
            }
            res[s.front()]=deck[i];
            return res;
    }
};