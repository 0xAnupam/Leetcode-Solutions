struct Node{
        char c;
        Node* next;
};
bool f(string &s,Node* root){
        Node* head=root;
        int i=0,n=s.size();
        while(i<n && head){
                while(head && head->c!=s[i]){
                        head=head->next;
                }
                if(head){
                        i++;
                        head=head->next;
                        
                }
                else{
                        return 0;
                }
                
        }
        return i==n;
}
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
                Node* root=new Node();
            Node* head=root;
            head->c=s[0];
            for(int i=1;i<s.size();i++){
                    head->next=new Node();
                    head=head->next;
                    head->c=s[i];
            }
            head->next=NULL;
            int cnt=0;
            string res="";
            for(auto &i:dictionary){
                    if(i.size()>=cnt && f(i,root)){
                            if(cnt==i.size()){
                                    res=min(res,i);
                            }
                            else{
                                    res=i;
                                  
                                    cnt=i.size();
                            }
                    }
            }
            return res;
    }
};