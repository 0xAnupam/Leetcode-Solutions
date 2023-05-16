stack<int> a,b;

class MinStack {
public:
        
    MinStack() {
        while(a.size()){
                a.pop();
        }
        while(b.size()){
                b.pop();
        }
    }
    
    void push(int val) {
        a.push(val);
        if(b.size()==0){
                b.push(val);
        }    
        else{
                b.push(min(val,b.top()));
        }    
    }
    
    void pop() {
        a.pop();
        b.pop();    
    }
    
    int top() {
        return a.top();
    }
    
    int getMin() {
        return b.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */