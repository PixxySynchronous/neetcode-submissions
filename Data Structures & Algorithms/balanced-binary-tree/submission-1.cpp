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
    pair<int, bool> solve ( TreeNode* root){
        if ( root == NULL)
            return {0,true}; 
        pair<int, bool> left = solve ( root -> left);
        pair<int, bool> right = solve ( root -> right);
        int heightBalanced = abs(left.first - right.first);
        int height = max (left.first, right.first) + 1; 
        bool balanced = false; 
        if (heightBalanced <= 1)
            balanced = true; 
        if (balanced && left.second && right.second)
            return {height, true}; 
        else return {height, false}; 
         
    }
    bool isBalanced(TreeNode* root) {
        pair<int, bool> ans = solve ( root); 
        return ans.second; 
    }
};
