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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return root;
    if(root->val == key) {
      if(!root->right){
        TreeNode* left = root->left;
        delete root;
        return left;
      }else{
        TreeNode* cur = root->right;
        while(cur->left) {
          cur = cur->left;
        }
        swap(root->val, cur->val);
      }
    }
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    return root;
  }
};
