class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        int max1 = -1;
        int max2 = -1;
        for(int i = 0;i<s.length();i++){
            int currNum = s[i]-'0';
            if(currNum > max2){
                if(currNum > max1){
                    int temp = max1;
                    max1 = currNum;
                    max2 = temp;
                }
                else{
                    max2 = currNum;
                }
            }
        }
        return max1 * max2;
    }
};