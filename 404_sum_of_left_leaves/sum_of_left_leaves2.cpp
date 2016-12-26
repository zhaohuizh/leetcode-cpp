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
  int sum_of_left_leaves(Tree_node* node, bool is_left) {
    if(node == NULL) return 0;
    if(is_left && !node->left && !node->right) return node->val;
    return sum_of_left_leaves(node->left, true) + sum_of_left_leaves(node->right, false);
  }

public:
  int sum_of_left_leaves(Tree_node* root) {
    return sum_of_left_leaves(root, false);
  }
};
