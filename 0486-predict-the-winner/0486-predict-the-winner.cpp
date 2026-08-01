class Solution {
public:
    int solve(int leftIdx,int rightIdx,vector<int>&nums,vector<vector<int>>&mem){
        if(leftIdx > rightIdx) return 0;
        if(mem[leftIdx][rightIdx] != -1) return mem[leftIdx][rightIdx];
        int left = nums[leftIdx] - solve(leftIdx+1,rightIdx,nums,mem);
        int right = nums[rightIdx] - solve(leftIdx,rightIdx-1,nums,mem);
        return mem[leftIdx][rightIdx] = max(left,right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n  = nums.size();

        vector<vector<int>>mem(n,vector<int>(n,-1));

        return solve(0,n-1,nums,mem) >= 0;
    }
};