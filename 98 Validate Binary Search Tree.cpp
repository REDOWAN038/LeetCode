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
    bool traverse(TreeNode* root,long min,long max){
        if(!root){
            return true;
        }

        long v = root->val;
        if(min>=v || max<=v){
            return false;
        }

        return (traverse(root->left,min,v) && traverse(root->right,v,max));
    }
    bool isValidBST(TreeNode* root) {
        return traverse(root,LONG_MIN,LONG_MAX);
    }
};