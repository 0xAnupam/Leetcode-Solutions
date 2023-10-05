class RecentCounter {
public:
    vector<int> arr;
    int n;
    int i=0;
    RecentCounter() {
        arr={};
        n=0;
        i=0;    
    }
    
    int ping(int t) {
        arr.emplace_back(t);
        n++;    
        while(i<n && t-arr[i]>3000){
                i++;
        }    
            return n-i;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */