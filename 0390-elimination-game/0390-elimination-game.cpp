int rl(int n);
int lr(int n){
        if(n==1){
                return 1;
        }
        return 2*rl(n/2);
}
int rl(int n){
        if(n==1){
                return 1;
        }
        return 2*lr(n/2)-(n+1)%2;
}
class Solution {
public:
    int lastRemaining(int n) {
        return lr(n);
    }
};