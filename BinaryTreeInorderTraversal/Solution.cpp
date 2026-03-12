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

class InterfaceInorderStrategy {
public:
  virtual vector<int> inorder(TreeNode *node) = 0;
  virtual ~InterfaceInorderStrategy() = default;
};

class RecursiveInorder : public InterfaceInorderStrategy {
public:
  vector<int> inorder(TreeNode *node) {
    if (!node)
      return res;
    if (node->left)
      inorder(node->left);
    res.emplace_back(node->val);
    if (node->right)
      inorder(node->right);
    return res;
  }

private:
  vector<int> res;
};

class IterativeInorder : public InterfaceInorderStrategy {
public:
  vector<int> inorder(TreeNode *node) {
    return {};
  }
};

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    unique_ptr<InterfaceInorderStrategy> traversalStrategy = make_unique<RecursiveInorder>();
    return traversalStrategy->inorder(root);
  }
};