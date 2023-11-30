struct node{
        
        int val;
        node* next;
        node* prev;
};
class MyCircularDeque {
public:
    node* front;
    node* rear;    
    int maxN;
    int n;    
    MyCircularDeque(int k) {
        front=nullptr;
            rear=nullptr;
            maxN=k;
            this->n=0;
    }
    
    bool insertFront(int value) {
        if(n>=maxN)return 0;
            if(n==0){n++;
                    front=rear=new node();
                    front->val=rear->val=value;
                    return 1;
            }
            node* newHead=new node();
            newHead->val=value;
            front->prev=newHead;
            newHead->next=front;
            front=newHead;
            n++;
            return 1;
    }
    
    bool insertLast(int value) {
        if(n>=maxN)return 0;
            if(n==0){n++;
                    front=rear=new node();
                    front->val=rear->val=value;
                    return 1;
            }
            node* newTail=new node();
            newTail->val=value;
            newTail->prev=rear;
            rear->next=newTail;
            rear=newTail;
            n++;
            return 1;
    }
    
    bool deleteFront() {
        if(n==0)return 0;
            front=front->next;
            n--;
            return 1;
    }
    
    bool deleteLast() {
        if(n==0)return 0;
            rear=rear->prev;
            n--;
            return 1;
    }
    
    int getFront() {
        if(n==0)return -1;
            return front->val;
    }
    
    int getRear() {
        if(n==0)return -1;
            return rear->val;
    }
    
    bool isEmpty() {
        return n==0;
    }
    
    bool isFull() {
        return n==maxN;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */