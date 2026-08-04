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

// BFS
class Solution1 {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;

        q.push(root);
        vector<int>res;
        while(!q.empty()){
            int n = q.size();
            TreeNode *node;
            while(n--){
                node = q.front();
                q.pop();
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }
            res.push_back(node->val);
        }
        return res;
    }
};


// DFS
class Solution {
public:
    void preOrder(TreeNode *root,int level,vector<int>&res){
        if(root==NULL) return;
        if(res.size() < level){
            res.push_back(root->val);
        }
        preOrder(root->right,level+1,res);
        preOrder(root->left,level+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        preOrder(root,1,res);
        return res;
    }
};