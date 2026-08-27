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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map <TreeNode*, TreeNode*> parents; 
        queue <TreeNode*> que; 
        que.push(root); 
        parents [root] = NULL; 
        while (!que.empty()){
            TreeNode* temp = que.front(); 
            que.pop(); 
            if ( temp -> left){
                que.push( temp -> left); 
                parents[temp -> left] = temp; 
            }
                
            if (temp -> right){
                que.push(temp -> right);
                parents [temp -> right] = temp; 
            }
               
        }
        unordered_set <TreeNode*> ancestor; 
        while (p != NULL){
            ancestor.insert(p) ; 
            p = parents[p]; 
        }
        while ( q!= NULL){
            if (ancestor.count(q))
                return q; 
            q = parents [q]; 
        }
        return NULL; 
    }
};
