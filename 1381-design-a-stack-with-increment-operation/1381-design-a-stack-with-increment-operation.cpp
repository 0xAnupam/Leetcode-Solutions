const int N=1e4+10;
int arr[N];
int n;
int idx;
class CustomStack {
public:
    CustomStack(int maxSize) {
        n=maxSize;
        idx=-1;
    }
    
    void push(int x) {
        if(idx+1<n){
                arr[++idx]=x;
        }
    }
    
    int pop() {
        if(idx==-1){
                return -1;
        }
            return arr[idx--];
    }
    
    void increment(int k, int val) {
        int cur=0;
        while(k && cur<=idx){
                arr[cur]+=val;
                k--;
                cur++;
        }   
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */