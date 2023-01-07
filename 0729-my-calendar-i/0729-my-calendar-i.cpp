
bool no_intersect(int a,int b,int s,int e){
        if(s<a){
                return e<=a;
        }
        else if(s>=b){
                return 1;
        }
        return 0;
}
vector<pair<int,int>> s;
class MyCalendar {
public:
        
        
    MyCalendar() {
        s.clear();
    }
    
    bool book(int start, int end) {
       for(auto &i:s){
               if(no_intersect(i.first,i.second,start,end)==0){
                       return 0;
               }
       }
            s.push_back({start,end});
            return 1;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */