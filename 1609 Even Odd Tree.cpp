//  1st approach :

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
    map<int, vector<int> > mp;
    void traverse(TreeNode* root, int d){
        if(root){
            mp[d].push_back(root->val);
            traverse(root->left, d+1);
            traverse(root->right, d+1);
        }
    }

    bool isEvenOddTree(TreeNode* root) {
        traverse(root, 0);
        
        for(auto [level, values]:mp){
            if(level%2){
                for(int i=0;i<values.size();i++){
                    if(values[i]%2){
                        return false;
                    }
                    if(i>0 && values[i]>=values[i-1]){
                        return false;
                    }
                }
            }else{
                for(int i=0;i<values.size();i++){
                    if(values[i]%2==0){
                        return false;
                    }
                    if(i>0 && values[i]<=values[i-1]){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};



// 2nd approach:
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
    bool isEvenOddTree(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        queue<TreeNode*>q;
        bool flag=true;
      
        q.push(root);
        while(!q.empty()){
            int x = q.size() ;
            int prev = flag ? INT_MIN : INT_MAX;
            for(int i=0; i< x; i++){
                TreeNode* frontNode = q.front();
                q.pop();  
                if(flag){
                    if(frontNode->val %2==0 || frontNode->val <=  prev){
                     return false;
                    }
                }
                else{
                    if(frontNode->val %2!=0  || frontNode->val  >= prev){
            
                        return false;
                    }
                }

                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
                prev= frontNode->val;
            }
            flag=!flag;
        }
        return true;
    }
};