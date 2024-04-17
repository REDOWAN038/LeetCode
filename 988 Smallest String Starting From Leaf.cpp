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
    string ans = "";
    
    void dfs(TreeNode* root, string s="") {
        if (!root) {
            return;
        }

        char c = root->val + 'a';
        string t = s+c;

        if(root->left==NULL && root->right==NULL){
            reverse(t.begin(),t.end());
            if(ans==""){
                ans = t;
            }else if(ans>t){
                ans = t;
            }
        }

        dfs(root->left, s + c);
        dfs(root->right, s + c);  
    }
    
    string smallestFromLeaf(TreeNode* root) {
        dfs(root);
        return ans;
    }
};