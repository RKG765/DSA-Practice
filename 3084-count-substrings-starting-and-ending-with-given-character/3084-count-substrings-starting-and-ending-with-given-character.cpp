class Solution {
public:
    long long countSubstrings(string s, char c) {
        int n = s.size();
        long long count = 0;
        for(char x:s){
            if(c==x){
                count++;
            }
        }
        return count*(count+1)/2;
    }
};
