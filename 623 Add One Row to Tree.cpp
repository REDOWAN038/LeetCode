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
    void addRow(TreeNode* root,int level,int depth,int val){
        if(root==NULL){
            return;
        }
        if(level==depth){
            TreeNode* temp=root->left;
            root->left=new TreeNode(val);
            root->left->left=temp;
            temp=root->right;
            root->right=new TreeNode(val);
            root->right->right=temp;
        }
        addRow(root->left,level+1,depth,val);
        addRow(root->right,level+1,depth,val);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }

        addRow(root,2,depth,val);
        return root;
    }
};