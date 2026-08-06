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
    TreeNode* solve(int &idx,int start,int end,vector<int>& inorder, vector<int>& postorder){
        if(start>end) return nullptr;
        
        int curr = postorder[idx];

        idx--;
        int i = start;
        for(;i<end;i++){
            if(curr==inorder[i]) break;
        }

        TreeNode* root = new TreeNode(curr);

        root->right =solve(idx,i+1,end,inorder,postorder);
        root->left =solve(idx,start,i-1,inorder,postorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int idx = n-1;
        return solve(idx,0,n-1,inorder,postorder);
    }
};