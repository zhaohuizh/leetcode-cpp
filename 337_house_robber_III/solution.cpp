#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int rob(TreeNode* root) {
    if (root == NULL) return 0;
    int value_with_root = root->val;
    if (root->left) {
      value_with_root += rob(root->left->left) + rob(root->left->right);
    }
    if (root->right) {
      value_with_root += rob(root->right->left) + rob(root->right->right);
    }
    return max(value_with_root, rob(root->left) + rob(root->right));
  }
};
