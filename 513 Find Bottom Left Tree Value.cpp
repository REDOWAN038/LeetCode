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
    int res=0,maxx=-1;

    void traverse(TreeNode* root, int d){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            if(d>maxx){
                res = root->val;
                maxx = d;
            }
            return;
        }
        traverse(root->left, d+1);
        traverse(root->right, d+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        traverse(root, 0);
        return res;
    }
};