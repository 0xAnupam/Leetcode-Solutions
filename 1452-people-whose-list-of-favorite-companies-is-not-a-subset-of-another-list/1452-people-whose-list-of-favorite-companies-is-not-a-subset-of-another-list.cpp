struct Tries{
        vector<int> idx;
        Tries* arr[26];      
};
void str(int ind,string &s,Tries* root){
        Tries* head=root;
        for(auto &i:s){
                if(head->arr[i-'a']==NULL){
                        head->arr[i-'a']=new Tries();
                }
                head=head->arr[i-'a'];
        }
        head->idx.push_back(ind);
}
bool f(vector<string>&word,int idx,int n,Tries* root){
        vector<int> fre(n,0);
        int m=word.size();
        fre[idx]--;
        for(auto &s:word){
                Tries* head=root;
                for(auto &i:s){
                        head=head->arr[i-'a'];
                }
                for(auto &i:head->idx){
                        fre[i]++;
                        if(fre[i]==m){
                                return 0;
                        }
                }
        }
        return 1;
}
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& com) {
        Tries* root=new Tries();
            int n=com.size();
            for(int i=0;i<n;i++){
                    for(auto &s:com[i]){
                            str(i,s,root);
                    }
            }
            vector<int> res;
            for(int i=0;i<n;i++){
                    if(f(com[i],i,n,root)){
                            res.push_back(i);
                    }
            }
            return res;
    }
};