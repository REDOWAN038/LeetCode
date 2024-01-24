/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bitset<10>mask=0;
    int res = 0;

    void dfs(TreeNode* root) {
        if(!root){
            return;
        }

        mask[root->val] = ~mask[root->val];
        if (!root->left && !root->right){
            if(mask.count()<=1){
                res+=1;
            }
            mask[root->val] = ~mask[root->val];
            return;
        }
        
        dfs(root->left);
        dfs(root->right);
        mask[root->val] = ~mask[root->val];
    }
    int pseudoPalindromicPaths(TreeNode* root) { 
        dfs(root); 
        return res;
    }
};