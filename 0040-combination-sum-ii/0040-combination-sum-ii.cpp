class Solution {
public:
    void solve(int pos,vector<int>&nums,int k,vector<vector<int>>&res,vector<int>&temp){
        if(k==0){
            res.push_back(temp);
            return;
        }
        
        for(int i = pos;i<nums.size();i++){
            if(pos<i && nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]>k) break;

            temp.push_back(nums[i]);
            solve(i+1,nums,k-nums[i],res,temp);
            // backtrack
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        sort(begin(candidates),end(candidates));
        solve(0,candidates,target,res,temp);
        return res;
    }
};