struct trie{
        trie* arr[2];
        int cnt=0;
};
void add(trie* root,int n){
        trie* head=root;
        for(int i=15;i>=0;i--){
            if((1<<i)&n){
                    if(head->arr[1]==nullptr){
                            head->arr[1]=new trie();
                    }
                    head=head->arr[1];
            }
            else{
                    if(head->arr[0]==nullptr){
                            head->arr[0]=new trie();
                    }
                    head=head->arr[0];
            }    
        }
        head->cnt++;
}
int f(int n,trie* head,int i){
        if(head==NULL){
                return 0;
        }
        if(i==-1){
                return head->cnt;
        }
        if((1<<i)&n){
                return f(n,head->arr[0],i-1);
        }
        return f(n,head->arr[0],i-1)+f(n,head->arr[1],i-1);
}
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        trie* head=new trie();
        int n=nums.size();
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        add(head,(nums[i]&nums[j]));
                }
        }
        sort(nums.begin(),nums.end());
        int i=0,res=0;
        while(i<n){
                int cnt=0,p=nums[i];
                while(i<n && nums[i]==p){
                        i++;
                        cnt++;
                }
                res+=(cnt*f(p,head,15));
        }    
        return res;
    }
};