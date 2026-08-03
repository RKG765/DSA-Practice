class Solution {
public:
    vector<int>mem;
    int solve(int i,vector<int>& stone){
        if(i>= stone.size()) return 0;
        int maxScore = INT_MIN;
        int currTake = 0;
        if(mem[i]!=-1) return mem[i];

        for(int k=0;k<3;k++){
            if(i+k < stone.size()){
            currTake += stone[k+i];

            int newScore = currTake - solve(i+k+1,stone);
            maxScore = max(newScore,maxScore);
            }
        }
        return mem[i]=maxScore;
    }
    string stoneGameIII(vector<int>& stone) {
        mem.resize(stone.size(),-1);
        int num = solve(0,stone);
        if(num>0){
            return "Alice";
        }
        else if(num<0) return "Bob";
        else return "Tie";
    }
};

class Solution1 {
public:
    int solve(int i,vector<int>& stone){
        if(i>=stone.size()) return 0;
        int take1 = 0, take2 = 0, take3 = 0;
        take1  = stone[i] - max(solve(i+1,stone),max(solve(i+2,stone),solve(i+3,stone)));
        if(i+1 < stone.size())
            take2  = stone[i]+stone[i+1] - max(solve(i+2,stone),max(solve(i+3,stone),solve(i+4,stone)));
        
        if(i+2 < stone.size())
            take3  = stone[i]+stone[i+2]+stone[i+1] - max(solve(i+3,stone),max(solve(i+4,stone),solve(i+5,stone)));
        return max(take1,max(take2,take3));
    }
    string stoneGameIII(vector<int>& stone) {
        int num = solve(0,stone);
        if(num>0) return "Alice";
        else if(num<0) return "Bob";
        else return "Tie";
    }
};