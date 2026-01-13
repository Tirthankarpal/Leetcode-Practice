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
    int sum=0;
    void cal(int num,TreeNode* root){
        if(root==NULL)return;
        if(root->left==NULL&&root->right==NULL){
            sum+=(num*10)+root->val;
            return;
        }
        cal((num*10)+root->val,root->left);
        cal((num*10)+root->val,root->right);
    }
    int sumNumbers(TreeNode* root) {
        cal(0,root);
        return sum;
    }
};