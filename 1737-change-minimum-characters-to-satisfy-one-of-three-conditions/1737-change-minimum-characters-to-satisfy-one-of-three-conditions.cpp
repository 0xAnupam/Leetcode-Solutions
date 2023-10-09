int op(vector<int>&x,vector<int>&y,int pivot){
        int res=0;
        for(int i=0;i<pivot;i++){
                res+=x[i];
        }
        for(int i=pivot;i<26;i++){
                res+=y[i];
        }
        
        return res;
        
}
class Solution {
public:
    int minCharacters(string &a, string &b) {
        vector<int> x(26,0),y(26,0);
            int n=a.size(),m=b.size();
            for(char &c:a){
                    x[c-'a']++;
            }
            for(char &c:b){
                    y[c-'a']++;
            }
            int res=n+m-x[0]-y[0];
            for(int i=1;i<26;i++){
                    res=min(res,op(x,y,i));
                    res=min(res,op(y,x,i));
                    res=min(res,n+m-x[i]-y[i]);
                    
            }
            return res;
            
    }
        
};