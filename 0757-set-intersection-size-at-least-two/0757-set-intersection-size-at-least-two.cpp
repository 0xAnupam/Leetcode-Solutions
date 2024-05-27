struct Vertex {
    int left, right;
    int sum = 0;
    Vertex *left_child = nullptr, *right_child = nullptr;

    Vertex(int lb, int rb) {
        left = lb;
        right = rb;
    }

    void extend() {
        if (!left_child && left + 1 < right) {
            int t = (left + right) / 2;
            left_child = new Vertex(left, t);
            right_child = new Vertex(t, right);
        }
    }

    void add(int k, int x) {
        extend();
        sum += x;
        if (left_child) {
            if (k < left_child->right)
                left_child->add(k, x);
            else
                right_child->add(k, x);
        }
    }

    int get_sum(int lq, int rq) {
        if (lq <= left && right <= rq)
            return sum;
        if (max(left, lq) >= min(right, rq))
            return 0;
        extend();
        return left_child->get_sum(lq, rq) + right_child->get_sum(lq, rq);
    }
};

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a ,const vector<int> &b){
           return a[1]==b[1] ? a[0]<b[0] : a[1]<b[1]; 
        });
        Vertex A(0,(int)1e8+1);
        int res=0;
        for(auto &i:intervals){
            int l=i[0],r=i[1];
            while(A.get_sum(l,i[1]+1)<2){
                while(A.get_sum(r,r+1))r--;
                A.add(r,1);
                r--;
                res++;
            }
        }
        return res;
    }
};