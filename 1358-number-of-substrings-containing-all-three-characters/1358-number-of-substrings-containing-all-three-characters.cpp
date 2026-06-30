class Solution {
public:
    int numberOfSubstrings(string s) {
        int last[3] = {-1,-1,-1};
        int res = 0;
        int n = s.length();

        for(int i = 0;i<n;i++){
            last[s[i]-'a']=i;

            if(last[0]!=-1 && last[1]!=-1 && last[2]!=-1){
                res+= min({last[0],last[1],last[2]})+1;
            }
        }
        return res;
    }
};


/*
// O(n^2) solution
class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        int n = s.length();

        for(int i=0;i<n;i++){
            int count[3] = {0};

            for(int j = i;j<n;j++){
                count[s[j]-'a']++;
                if(count[0]>0 && count[1]>0 && count[2]>0){
                    res++;
                }
            }
        }
        return res;
    }
};



// O(N^3) Solution TLE
class Solution {
public:

    bool isValid(string temp){
        if(temp.find('a')!= string::npos && temp.find('b')!=string::npos &&temp.find('c')!=string::npos){
            return true;
        }
        return false;
    }
    int numberOfSubstrings(string s) {
        int n = s.length();
        int res = 0;

        for(int i = 0;i<n;i++){
            string temp;
            for(int j = i;j<n;j++){
                temp.push_back(s[j]);

                if(j>=2){
                    if(isValid(temp)){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
*/