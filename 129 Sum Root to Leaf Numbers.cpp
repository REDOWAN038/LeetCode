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
    int sum=0;

    void calcSum(TreeNode* root, int v){
        if(root){
            if(root->left==NULL && root->right==NULL){
                sum+=(root->val+(10*v));
            }
            calcSum(root->left, root->val+(10*v));
            calcSum(root->right, root->val+(10*v));
        }
    }

    int sumNumbers(TreeNode* root) {
        calcSum(root,0);
        return sum;
    }
};