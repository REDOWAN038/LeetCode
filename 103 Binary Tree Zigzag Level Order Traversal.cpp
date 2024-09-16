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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;

        if(!root){
            return res;
        }

        deque<TreeNode*>dq;
        dq.push_back(root);
        int lvl = 0;

        while(!dq.empty()){
            int sz = dq.size();
            vector<int>temp;

            while(sz--){
                if(lvl%2==0){
                    TreeNode* curr = dq.back();
                    dq.pop_back();
                    temp.push_back(curr->val);
                    if(curr->left){
                        dq.push_front(curr->left);
                    }
                    if(curr->right){
                        dq.push_front(curr->right);
                    }
                }else{
                    TreeNode* curr = dq.front();
                    dq.pop_front();
                    temp.push_back(curr->val);
                    if(curr->right){
                        dq.push_back(curr->right);
                    }
                    if(curr->left){
                        dq.push_back(curr->left);
                    }
                }
            }

            res.push_back(temp);
            lvl++;
        }

        return res;
    }
};