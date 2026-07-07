class Solution {
public:
    typedef long long ll;
    long long sumAndMultiply(int n) {
        ll temp = (ll)n;
        ll x = 0;
        ll sum =0;
        while(temp!=0){
            ll digit = temp%10;
            if(digit!=0){
                x = x*10+digit;
                sum+=digit;
            }
            temp/=10;
        }
        //reverse the x
        ll rev = x;
        x = 0;
        while(rev!=0){
            ll digit = rev%10;
            x = x*10+digit;
            rev/=10;
        }
        return x*sum;
    }
};