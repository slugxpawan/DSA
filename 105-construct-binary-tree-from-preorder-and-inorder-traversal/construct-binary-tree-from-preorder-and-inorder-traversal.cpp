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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int, int> inMap;

    
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1, inMap);
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    unordered_map<int, int>& inMap) {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        
        int rootValue = preorder[preStart];

        TreeNode* root = new TreeNode(rootValue);

        int rootIndex = inMap[rootValue];
        int leftSize = rootIndex - inStart;

        root->left = build(
            preorder,
            preStart + 1,
            preStart + leftSize,
            inorder,
            inStart,
            rootIndex - 1,
            inMap
        );

        root->right = build(
            preorder,
            preStart + leftSize + 1,
            preEnd,
            inorder,
            rootIndex + 1,
            inEnd,
            inMap
        );

        return root;
    }
};