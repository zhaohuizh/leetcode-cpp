#include <iostream>
using namespace std;

struct Tree_node {
  int val;
  Tree_node* left;
  Tree_node* right;
  Tree_node(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  void helper(Tree_node* node, int* ret, bool left) {
    if (node->left == NULL && node->right == NULL) {
      if (left) (*ret)++;
      return;
    }
    if (node->left != NULL) {
      helper(node->left, ret, true);
    }
    if (node->right != NULL) {
      helper(node->right, ret, false);
    }

  }

public:
  int sum_of_left_leaves(Tree_node* root) {
    if (root == NULL) return 0;
    int ret = 0;
    helper(root, &ret, false);
    return ret;
  }
};
