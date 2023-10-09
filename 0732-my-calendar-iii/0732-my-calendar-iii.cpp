class MyCalendarThree {
public:
        map<int,int> booking;
    MyCalendarThree() {
        booking.clear();
    }
    
    int book(int start, int end) {
        booking[start]++;
        booking[end]--;
            int sum=0,res=0;
            for(auto &i:booking){
                    sum+=i.second;
                    res=max(res,sum);
            }
            return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */