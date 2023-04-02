// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
 int n=0;
class Solution {
public:
    int rand10() {n++;
        return (rand7()+rand7()+n)%10+1;
    }
};