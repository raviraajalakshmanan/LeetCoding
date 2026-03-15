/**
https://leetcode.com/problems/binary-tree-postorder-traversal/description/
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]
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

class IterativePostOrderTwoStacks : public InterfacePostorderStrategy {
public:
  vector<int> postorder(TreeNode *node) {
    if (!node)
      return res;

    st1.push(node);
    while (!st1.empty()) {
      auto curr = st1.top();
      st1.pop();
      st2.push(curr);
      if (curr->left)
        st1.push(curr->left);
      if (curr->right)
        st1.push(curr->right);
    }
    while (!st2.empty()) {
      res.emplace_back(st2.top()->val);
      st2.pop();
    }
    return res;
  }

private:
  vector<int> res;
  stack<TreeNode *> st1;
  stack<TreeNode *> st2;
};

class IterativePostOrderSingleStacks : public InterfacePostorderStrategy {
public:
  vector<int> postorder(TreeNode *node) {
    if (!node)
      return res;
    while (node || !st.empty()) {
      while (node) {
        st.push(node);
        node = node->left;
      }
      node = st.top();

      if (node->right && lastVisited != node->right) {
        node = node->right;
      } else {
        res.emplace_back(node->val);
        st.pop();
        lastVisited = node;
        node = nullptr;
      }
    }
  }

private:
  vector<int> res;
  stack<TreeNode *> st;
  TreeNode *lastVisited = nullptr;
};

class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    unique_ptr<InterfacePostorderStrategy> traversalStrategy =
        make_unique<IterativePostOrderSingleStacks>();
    return traversalStrategy->postorder(root);
  }
};