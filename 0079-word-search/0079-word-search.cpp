class Solution {
public:
    vector<vector<int>>dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    int n,m;
    bool solve(int i,int j,int idx,vector<vector<char>>&board,string &word){
        if(idx==word.length()) return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='$') return false;

        if(board[i][j]!=word[idx]) return false;

        board[i][j] = '$';

        for(auto &dir:dirs){
            int i_ = i+dir[0];
            int j_ = j+dir[1];
            if(solve(i_,j_,idx+1,board,word))return true;
        }
        board[i][j] = word[idx];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n  = board[0].size();

        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j]==word[0] && solve(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};