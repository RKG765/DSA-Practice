class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        int num = 0;

        // skipping the ' ' spaces
        while(i<n && s[i]==' ') i++;

        //checking the sign

        // while(i<n && (s[i]=='+' || s[i]=='-')){
        //     if(s[i]=='-') sign = -1;
        //     i++;
        // }
        if(i < n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-') sign = -1;
            i++;
        }

        // checking the values and also the overflow

        while(i<n && isdigit(s[i])){
            int digit = s[i]-'0';

            if(num > INT_MAX/10 || (num == INT_MAX/10 && digit > 7 )){
                return (sign == 1) ? INT_MAX:INT_MIN;
            }
            num = num * 10 + digit;
            i++;
        }

        return sign * num;
    }
};

class Solution1 {
public:
    bool isAlpha(char s){
        int n= int(s);
        if((n>=65 && n<=90) || (n>=97 && n<=122)) return 1;
        return 0;
    }
    int myAtoi(string s) {
        int num =0;
        bool sign = false;
        for(int i = 0;i<s.length();i++){
            if(s[i]==' ' || s[i]=='.') continue;
            if(s[i]=='-') sign=1;
            if(isAlpha(s[i])) break;
            if(s[i]-'0'>0) num*10+(s[i]-'0');
        }
        if(sign) return num - (2*num);
        return num;
    }
};