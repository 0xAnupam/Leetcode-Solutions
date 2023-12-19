struct Tries{
        Tries* arr[2];
        int cnt=0;
};
void ins(Tries* root,int N){
        Tries* head=root;
        for(int i=15;i>=0;i--){
                bool f=((1<<i)&N)>0;
                if(head->arr[f]==nullptr)head->arr[f]=new Tries();
                head=head->arr[f];
                head->cnt++;
        }
        
}
int f(int i,Tries* head,int cur,int N,int ele){
        if(head==nullptr)return 0;
        if(cur>N)return head->cnt;
        if(i==-1){
                return 0;
        }
        if((1<<(i+1))+cur<=N)return 0;
        bool flag=((1<<i)&ele)>0;
        if(flag){
                return f(i-1,head->arr[0],cur+(1<<i),N,ele)+f(i-1,head->arr[1],cur,N,ele);
        }
        return f(i-1,head->arr[1],cur+(1<<i),N,ele)+f(i-1,head->arr[0],cur,N,ele);
}
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        Tries* root=new Tries();
        int res=0;
        for(auto &i:nums){
                ins(root,i);
                res+=(f(15,root,0,low-1,i)-f(15,root,0,high,i));
        }    
            return res;
    }
};