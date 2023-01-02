class Solution {
public:
    int minSwaps(string &S) {
        stack<int>s;
            for(auto &i:S){
                    if(i=='['){
                            s.push(i);
                    }
                    else if(s.size() && s.top()=='['){
                            s.pop();
                    }
                    else{
                            s.push(i);
                    }
            }
            return (3+s.size())/4;
    }
};