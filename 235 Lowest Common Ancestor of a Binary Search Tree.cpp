/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int getDir(TreeNode* root, TreeNode* p, TreeNode* q){
        if(p->val <= root->val && q->val >= root->val){
            return 0;
        }else if(p->val >= root->val && q->val <= root->val){
            return 0;
        }else if(p->val < root->val && q->val < root->val){
            return -1;
        }else{
            return 1;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int dir = getDir(root,p,q);
        if(dir==0){
            return root;
        }else if(dir==-1){
            return lowestCommonAncestor(root->left,p,q);
        }else{
            return lowestCommonAncestor(root->right,p,q);
        }
    }
};