struct Tries{ 
Tries* arr[26];
int  f=0;
};

bool F(string &s,Tries* root){
        Tries* head=root;
        for(auto &i:s){
                head=head->arr[i-'a'];
                if(head->f==0){
                        return 0;
                }
        }
        return 1;
}
class Solution {
public:
    string longestWord(vector<string>& words) {
        Tries* root=new Tries();
        for(auto &i:words){
                Tries* head=root;
                for(auto &j:i){
                        if(head->arr[j-'a']==NULL){
                                head->arr[j-'a']=new Tries();
                        }
                        head=head->arr[j-'a'];
                }
                head->f=1;
        }
            string res="";
            int cnt=0;
            for(auto &i:words){
                    if(i.size()>=cnt && F(i,root)){
                        //    cout<<i<<'\n';
                            if(i.size()==cnt){
                                    res=min(res,i);
                            }
                            else{
                                    cnt=i.size();
                                    res=i;
                            }
                    }
            }
            return res;
    }
};