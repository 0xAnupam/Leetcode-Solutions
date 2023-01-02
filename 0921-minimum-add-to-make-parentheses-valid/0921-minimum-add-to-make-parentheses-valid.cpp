class Solution {
public:
    int minAddToMakeValid(string &S) {
        stack<int>s;
            for(auto &i:S){
                    if(i=='('){
                            s.push(i);
                    }
                    else if(s.size() && s.top()=='('){
                            s.pop();
                    }
                    else{
                            s.push(i);
                    }
            }
            return s.size();
    }
};