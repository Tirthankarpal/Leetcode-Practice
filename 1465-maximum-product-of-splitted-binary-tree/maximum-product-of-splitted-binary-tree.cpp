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
    typedef long long ll;
    ll mod=1e9+7;
    ll sum(TreeNode* root,map<TreeNode*,ll>& mp){
        if(root==NULL)return 0;
        else return mp[root]=(root->val+sum(root->left,mp)+sum(root->right,mp))%mod;
    }
    ll ans=0;
    void cal(TreeNode* root,TreeNode* par,map<TreeNode*,ll>& mp){
        if(root==NULL)return;
        else{
            if(root->left!=NULL)ans=max(ans,(((mp[par]-mp[root->left]))*(mp[root->left])));
            if(root->right!=NULL)ans=max(ans,(((mp[par]-mp[root->right]))*(mp[root->right])));
        }
        cal(root->left,par,mp);
        cal(root->right,par,mp);
    }
    int maxProduct(TreeNode* root) {
        map<TreeNode*,ll> mp;
        ans=0;
        mp[root]=sum(root,mp);
        cal(root,root,mp);
        return ans%mod;
    }
};