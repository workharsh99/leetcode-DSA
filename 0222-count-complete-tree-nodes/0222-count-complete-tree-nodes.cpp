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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int leftnode = 0, rightnode = 0;
        TreeNode* leftPtr = root;
        TreeNode* rightPtr = root;
        
        while (leftPtr) {
            leftnode++;
            leftPtr = leftPtr->left;
        }
        
        while (rightPtr) {
            rightnode;
            rightPtr = rightPtr->right;
        }
        
        if (leftnode == rightnode) {
            return (1 << leftnode) - 1; 
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};