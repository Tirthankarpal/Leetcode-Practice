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
    int depth(TreeNode* root){
        if(root==NULL)return 0;
        return 1+max(depth(root->left),depth(root->right));
    }
    int cnt(int lvl,int t,TreeNode* root,map<TreeNode*,int>& mp){
        if(root==NULL)return 0;
        if(lvl==t)return mp[root]=1;
        return mp[root]=cnt(lvl+1,t,root->left,mp)+cnt(lvl+1,t,root->right,mp);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int t=depth(root);
        map<TreeNode*,int> mp;
        int tot=cnt(1,t,root,mp);
        TreeNode* ans=NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
           TreeNode* r=q.front();
           q.pop();
           if(mp[r]==tot)ans=r;
           if(r->left!=NULL)q.push(r->left); 
           if(r->right!=NULL)q.push(r->right); 
        }
        return ans;
    }
};