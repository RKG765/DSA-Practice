/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // it's like binary search pick low high mid then recusivly search into it 
    TreeNode* solve(int start,int end,vector<int>& nums){
        if(start>end) return nullptr;

        int mid = start + (end-start)/2;

        TreeNode* res = new TreeNode(nums[mid]);

        // recursively go left and right 
        res->left = solve(start,mid-1,nums);
        res->right = solve(mid+1,end,nums);

        return res;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0,nums.size()-1,nums);
    }
};