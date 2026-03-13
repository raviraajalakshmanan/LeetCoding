#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class InterfacePostorderStrategy {
public:
  virtual vector<int> postorder(TreeNode *node) = 0;
  virtual ~InterfacePostorderStrategy() = default;
};

class RecursiveInorder : public InterfacePostorderStrategy {
public:
  vector<int> postorder(TreeNode *node) {
    if (!node)
      return res;
    if (node->left)
      postorder(node->left);
    if (node->right)
      postorder(node->right);
    res.emplace_back(node->val);
    return res;
  }

private:
  vector<int> res;
};

class IterativeInorder : public InterfacePostorderStrategy {
public:
  vector<int> postorder(TreeNode *node) {
    return {};
  }
};

class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    unique_ptr<InterfacePostorderStrategy> traversalStrategy = make_unique<RecursiveInorder>();
    return traversalStrategy->postorder(root);
  }
};