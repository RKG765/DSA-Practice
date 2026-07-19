class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>lastSeen(26,0);
        vector<bool>visited(26,false);
        if(s.length()==1) return s;
        for(int i = 0;i<s.length();i++){
            lastSeen[s[i]-'a'] = i;
        }
        string res = "";

        for(int i = 0;i<s.length();i++){
            int currEle = s[i];

            if(visited[currEle-'a']) continue;

            while(!res.empty() && currEle < res.back() && lastSeen[res.back()-'a']>i){
                visited[res.back()-'a'] = false;
                res.pop_back();
            }

            res.push_back(currEle);
            visited[currEle -'a'] = true;
        }
        return res;
    }
};