//Greedy Apporach 
class Solution{
public:
 vector<int> validSequence(string word1, string word2){
        int m = word2.size();
        int n = word1.size();
        vector<int>last(n,0);
        int canChange = 0;
        int idx = m-1;
        for(int i = n-1;i>=0;i--){
            if(idx>=0 && word2[idx] == word1[i]){
                canChange++;
                idx--;
            }
            last[i] = canChange;
        }
        bool usedPower = false;
        vector<int>res;
        int i = 0;int j = 0;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                res.push_back(i);
                j++;
            }
            else if(usedPower==0 &&i+1<n &&last[i+1]>= (m-j-1)){
                res.push_back(i);
                j++;
                usedPower = 1;
            }
            i++;
        }
        return j==m? res : vector<int>();
        
    }
};

// MLE and TLE but solution is good
class Solution2{
public:
    vector<vector<vector<int>>>mem;
    bool solve(int x,int y,bool changed,string &word1, string &word2,vector<int>&res){
        if(y==word2.size()) return 1;
        if(x == word1.size()) return false;
        if(mem[x][y][changed]!=-1) return mem[x][y][changed];
        if(word1[x]==word2[y]){
            res.push_back(x);
            if(solve(x+1,y+1,changed,word1,word2,res)) return mem[x][y][changed]=true;
            res.pop_back();
        }
        else if(!changed){
        // chnage krunga
            res.push_back(x);
            if(solve(x+1,y+1,true,word1,word2,res)) return mem[x][y][changed]=true;
            res.pop_back();
        }
        
        if(solve(x+1,y,changed,word1,word2,res)) return mem[x][y][changed]=true;
        return mem[x][y][changed]=false;
    }
    vector<int> validSequence(string word1, string word2){
        vector<int> res;
        mem.resize(word1.size(),vector<vector<int>>(word2.size(),vector<int>(2,-1)));
        if (solve(0, 0, false, word1, word2, res)) return res;
        return {};
    }
};

////////////////////////////////////////////////

class Solution1 {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int>res;
        int j = 0;
        //chnage kiye mil jaye
        for(int i = 0;i<n;i++){
            if(word1[i] == word2[j]){
                res.push_back(i);
                j++;
            }
        }
        if(res.size()==m) return res;


        // 1 change{}
        if(res.size()==0){
            res.push_back(0);
        }
        else res.push_back(res[j-1]+1);
        j++;
        for(int i = res[j-1]+1;i<n;i++){
            if(word1[i]==word2[j]){
                res.push_back(i);
                j++;
            }
        }
        if(res.size()==m) return res;
        return {};
    }
};