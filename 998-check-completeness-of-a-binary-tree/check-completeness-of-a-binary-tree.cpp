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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool nullfound = false;
        while(!q.empty()){
            TreeNode* Node= q.front();
            q.pop();

            if(Node==nullptr){
                nullfound = true;
                continue;
            }
         if(nullfound) return false;

         q.push(Node->left);
         q.push(Node->right);

        }
        return true;
    }
};