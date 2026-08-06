class Solution {
public:
    int digit(int n){
        if (n<10) return n;
        return n%10 * digit(n/10);
    }
    int smallestNumber(int n, int t) {
        while(1){
            if(!(digit(n)%t)) return n;
            n++;
        }
    }
};