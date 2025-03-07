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
void inorder(TreeNode*root,vector<TreeNode*>&ans){
    if(root==NULL){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root);
    inorder(root->right,ans);
}
TreeNode*connection(int l,int h,vector<TreeNode*>&ans){
    if(l>h){
        return NULL;
    }
    int mid=(l+h)/2;
    ans[mid]->left=connection(l,mid-1,ans);
    ans[mid]->right=connection(mid+1,h,ans);
    return ans[mid];
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>ans;
        inorder(root,ans);
        return connection(0,ans.size()-1,ans);
    }
};