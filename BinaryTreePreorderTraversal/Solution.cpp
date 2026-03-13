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

class InterfacePreorderStrategy {
public:
  virtual vector<int> preorder(TreeNode *node) = 0;
  virtual ~InterfacePreorderStrategy() = default;
};

class RecursivePreorder : public InterfacePreorderStrategy {
public:
  vector<int> preorder(TreeNode *node) {
    if (!node)
      return res;
    res.emplace_back(node->val);
    if (node->left)
      preorder(node->left);
    if (node->right)
      preorder(node->right);
    return res;
  }

private:
  vector<int> res;
};

class Iterativepreorder : public InterfacePreorderStrategy {
public:
  vector<int> preorder(TreeNode *node) {
    return {};
  }
};

class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    unique_ptr<InterfacePreorderStrategy> traversalStrategy = make_unique<RecursivePreorder>();
    return traversalStrategy->preorder(root);
  }
};