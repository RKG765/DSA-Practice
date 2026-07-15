class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;
        int m = n;
        int num1 = 1;
        int num2 =1;
        while(n){
            if(num1 % 2!=0){
                sumOdd+=num1;
                n--;
            }
            num1++;
        }
        while(m){
            if(num2%2==0){
                sumEven+=num2;
                m--;
            }
            num2++;
        }

        return gcd(sumOdd,sumEven);
    }
};