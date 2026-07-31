class Solution {
public:
    int minimumPushes(string word) {
        int n  = word.length();

        vector<int>freq(26,0);

        for(int i = 0;i<n;i++){
            freq[word[i]-'a']++;
        }

        sort(freq.begin(),freq.end(),greater<int>());
        int res = 0;
        int count = 0;
        int rank = 1;
        for(int i=0;i<26;i++){
            count++;
            res+= freq[i]*rank;
            if(count==8){
                rank++;
                count = 0;
            }
        }
        return res;
    }
};