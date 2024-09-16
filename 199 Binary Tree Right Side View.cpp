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
    map<int,int>mp;

    void traverse(TreeNode* root,int d){
        if(!root){
            return;
        }

        mp[d] = root->val;
        traverse(root->left,d+1);
        traverse(root->right,d+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        traverse(root,0);

        for(auto it:mp){
            res.push_back(it.second);
        }

        return res;
    }
};