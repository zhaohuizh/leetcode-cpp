#include <iostream>
#include <stack>
using namespace std;

struct Tree_node {
  int val;
  Tree_node* left;
  Tree_node* right;
  Tree_node(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int sum_of_left_leaves(Tree_node* root) {
    if(root == NULL) return 0;
    int ret = 0;
    stack<Tree_node*> nodes;
    nodes.push(root);
    while(!nodes.empty()) {
      Tree_node* cur = nodes.top();
      nodes.pop();
      if(cur->left && !cur->left->left && !cur->left->right){
        ret += cur->left->val;
      }
      if(cur->left) nodes.push(cur->left);
      if(cur->right) nodes.push(cur->right);
    }
    return ret;
  }
};
