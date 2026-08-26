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
    int solve (TreeNode* root, int& diameter){
        if (root == NULL)
            return -1; 
        int h1 = solve (root -> left, diameter); 
        int h2 = solve (root -> right, diameter); 
        int height = max (h1, h2) + 1; 
        int currDiam = h1+h2+2; 
        diameter = max (currDiam, diameter); 
        return height; 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0; 
        int ans = solve (root, diameter);
        return diameter; 
    }
};
