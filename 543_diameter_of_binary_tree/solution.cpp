#include <iostream>
#include <algorithm>
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
private:
  int dfs(TreeNode* node, int* ret) {
    int left = 0;
    int right = 0;
    if (node->left) left = dfs(node->left, ret);
    if (node->right) right = dfs(node->right, ret);
    *ret = max (*ret, left + right);
    return max(left + 1, right + 1);
  }

public:
  int diameter_of_binary_tree(TreeNode* root) {
    int ret = 0;
    if (root)
      dfs(root, &ret);
    return ret;
  }
  
};
