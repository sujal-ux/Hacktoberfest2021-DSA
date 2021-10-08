#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int ans=INT_MIN;
    
int traverse(TreeNode* root) {
    if(!root)
        return 0;
    int ltreesum = max(0,traverse(root->left));
    int rtreesum = max(0,traverse(root->right));
    ans=max(ans,root->val + ltreesum + rtreesum);
    return root->val + max({0,ltreesum,rtreesum});
}

int maxPathSum(TreeNode* root) {
    traverse(root);
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout<<maxPathSum(root);
}
