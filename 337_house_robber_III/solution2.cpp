#include <iostream>
#include <map>
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
  map<TreeNode*, int> val_map;

public:
  int rob(TreeNode* root) {
    if (root == NULL) return 0;
    if (val_map.find(root) != val_map.end()) return val_map[root];
    int value = root->val;
    if (root->left) {
      value += rob(root->left->left) + rob(root->left->right);
    }
    if (root->right) {
      value += rob(root->right->left) + rob(root->right->right);
    }
    value = max(value, rob(root->left) + rob(root->right));
    val_map.insert(pair<TreeNode*, int>(root, value));
    return value;
  }
};
