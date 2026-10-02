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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int, int> inMap;

        
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return build(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1,
                     inMap);
    }

    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd,
                    unordered_map<int, int>& inMap) {

        
        if (inStart > inEnd || postStart > postEnd)
            return NULL;

        
        int rootValue = postorder[postEnd];

        TreeNode* root = new TreeNode(rootValue);

        
        int rootIndex = inMap[rootValue];

        
        int leftSize = rootIndex - inStart;

        
        root->left = build(
            inorder,
            inStart,
            rootIndex - 1,
            postorder,
            postStart,
            postStart + leftSize - 1,
            inMap
        );
        root->right = build(
            inorder,
            rootIndex + 1,
            inEnd,
            postorder,
            postStart + leftSize,
            postEnd - 1,
            inMap
        );

        return root;
    }
};
