class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int count =1;
        int res = 0;
        while(n!=0){
            res += min(n,8)*count;
            count++;
            n-= min(n,8);
        }
        return res;
    }
};