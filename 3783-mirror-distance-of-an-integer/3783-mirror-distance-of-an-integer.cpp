#include<cmath>
class Solution {
public:
    int mirrorDistance(int n) {
     int temp = n;
     int rev=0;
     while(temp){
        int last = temp%10;
        rev = rev * 10 + last;
        temp/=10;
     }   
     return abs(rev-n);
    }
};