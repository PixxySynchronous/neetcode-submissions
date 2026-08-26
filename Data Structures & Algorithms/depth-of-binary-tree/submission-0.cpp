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
    int solve (TreeNode* root){
        if (root == NULL)
            return 0; 
        int leftTree = solve (root -> left); 
        int rightTree = solve (root -> right); 
        int ans = max (rightTree, leftTree) + 1; 
        return ans; 
    }
    int maxDepth(TreeNode* root) {
        int ans = solve (root); 
        return ans; 
    }
};
