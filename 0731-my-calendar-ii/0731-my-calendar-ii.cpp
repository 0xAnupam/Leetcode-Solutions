class MyCalendarTwo {
public:
    map<int,int> booking;    
    MyCalendarTwo() {
        booking.clear();
    }
    
    bool book(int start, int end) {
        booking[start]++;
        booking[end]--;
            int sum=0;
            for(auto &i:booking){
                    sum+=i.second;
                    if(sum>2){
                            if(booking[start]==1){
                                    booking.erase(start);
                            }
                            else{
                                booking[start]--;
                            }
                            if(booking[end]==-1){
                                    booking.erase(end);
                            }else{
                                booking[end]++;
                            }
                            return 0;
                    }
            }
            return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */