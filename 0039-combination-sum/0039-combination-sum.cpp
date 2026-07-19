class Solution {
public:
    void solve(int pos,int target,vector<int>&nums,vector<vector<int>>&res,vector<int>&temp){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(pos==nums.size()) return;
        //pick

        if(nums[pos]<= target){
            temp.push_back(nums[pos]);
            solve(pos,target-nums[pos],nums,res,temp);
            temp.pop_back();
        }
        // not pick
        solve(pos+1,target,nums,res,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        solve(0,target,candidates,res,temp);
        return res;
    }
};