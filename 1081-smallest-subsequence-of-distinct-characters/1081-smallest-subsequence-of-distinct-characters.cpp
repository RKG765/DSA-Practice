class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>lastSeen(26,0);
        vector<bool>visited(26,false);
        string res = "";
        // lastSeen where the elements are last seen in pos
        for(int i =0;i<s.length();i++){
            lastSeen[s[i]-'a'] = i;
        }

        for(int i = 0;i<s.length();i++){
            int currEle= s[i];

            if(visited[currEle -'a']) continue;
            while(!res.empty() && currEle< res.back() && lastSeen[res.back()-'a']>i){
                visited[res.back()-'a'] = false;
                res.pop_back();
            }

            res.push_back(currEle);
            visited[currEle -'a']=true;  
        }
        return res;
    }
};