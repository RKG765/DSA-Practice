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
    void bfs(TreeNode* root,vector<vector<int>>&res){
        if(root==nullptr) return;
        queue<TreeNode*>node;
        node.push(root);
        while(!node.empty()){
            int n = node.size();
            vector<int>level;
            for(int i = 0;i<n;i++){
                TreeNode* temp = node.front();
                node.pop();
                level.push_back(temp->val);

                if(temp->left != nullptr) node.push(temp->left);
                if(temp->right !=nullptr) node.push(temp->right);
            }
                res.push_back(level);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr) return vector<vector<int>>();
        vector<vector<int>>res; 
        bfs(root,res);
        reverse(res.begin(),res.end());
        return res;
    }
};