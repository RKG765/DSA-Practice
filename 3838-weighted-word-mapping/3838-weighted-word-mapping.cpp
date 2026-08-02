class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s ="";
        
       for(auto &x:words){
            int sum = 0;
            for(auto &y:x){
                sum+= weights[y-'a'];
            }
            sum %= 26;
            s.push_back('z'-sum);
       } 
       return s;
    }
};