/**
https://leetcode.com/problems/binary-tree-preorder-traversal/description/
Given the root of a binary tree, return the preorder traversal of its nodes' values.
Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]
*/

#include <iostream>
#include <memory>
#include <stack>
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
    if (!node)
      return res;
    st.push(node);
    while (!st.empty()) {
      auto curr = st.top();
      res.emplace_back(curr->val);
      st.pop();
      if (curr->right)
        st.push(curr->right);
      if (curr->left)
        st.push(curr->left);
    }

    return res;
  }

private:
  vector<int> res;
  stack<TreeNode *> st;
};

class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    unique_ptr<InterfacePreorderStrategy> traversalStrategy = make_unique<Iterativepreorder>();
    return traversalStrategy->preorder(root);
  }
};