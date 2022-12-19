class Solution {
public:
        struct Tries{
           int c=0;
           Tries* arr[26];
        };
    vector<int> sumPrefixScores(vector<string>& words) {
        Tries* root=new Tries();
            for(auto &i:words){
                    Tries* newHead=root;
                    for(auto &j:i){
                            if(newHead->arr[j-'a']==NULL){
                                    newHead->arr[j-'a']=new Tries();
                                    newHead->arr[j-'a']->c=newHead->arr[j-'a']->c+1;
                            }
                            else{
                                   newHead->arr[j-'a']->c=newHead->arr[j-'a']->c+1;
                            }
                            newHead=newHead->arr[j-'a'];
                    }
            }
            vector<int> res;
            for(auto &i:words){
                    int ans=0;
                    Tries* newHead=root;
                    for(auto &j:i){
                            
                            newHead=newHead->arr[j-'a'];
                            ans+=newHead->c;
                    }
                    res.push_back(ans);
            }
            return res;
    }
};