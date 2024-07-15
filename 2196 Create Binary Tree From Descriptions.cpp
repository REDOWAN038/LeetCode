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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>node;
        unordered_set<int>child;

        for(int i=0;i<descriptions.size();i++){
            int pv = descriptions[i][0];
            int cv = descriptions[i][1];
            int isLeft = descriptions[i][2];

            if(node.find(pv)==node.end()){
                node[pv] = new TreeNode(pv);
            }

            if(node.find(cv)==node.end()){
                node[cv] = new TreeNode(cv);
            }

            if(isLeft){
                node[pv]->left = node[cv];
            }else{
                node[pv]->right = node[cv];
            }

            child.insert(cv);
        }

        for(auto it:node){
            if(child.find(it.first)==child.end()){
                return it.second;
            }
        }

        return nullptr;
    }
};