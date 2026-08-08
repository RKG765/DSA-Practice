/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(int s,int e,vector<int>&res){
        if(s>e) return nullptr;

        int mid = s+ (e-s)/2;

        TreeNode* root = new TreeNode(res[mid]);

        root->left = solve(s,mid-1,res);
        root->right = solve(mid+1,e,res);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        //convert the linkedlist into array so you can get the start and end means how many elements are there in linked list
        vector<int>res;
        while(head !=nullptr){
            res.push_back(head->val);
            head = head->next; 
        }
        return solve(0,res.size()-1,res);
    }
};