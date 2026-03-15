/**
https://leetcode.com/problems/binary-tree-inorder-traversal/

Given the root of a binary tree, return the inorder traversal of its nodes' values.
Input: root = [1,null,2,3]
Output: [1,3,2]

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,2,6,5,7,1,3,9,8]

Input: root = []
Output: []

Input: root = [1]
Output: [1]
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
    while (node || !st.empty()) {
      while (node) {
        st.push(node);
        node = node->left;
      }
      node = st.top();
      st.pop();
      res.emplace_back(node);
      node = node->right;
    }
  }

private:
  vector<int> res;
  stack<TreeNode *> st;
};

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    unique_ptr<InterfaceInorderStrategy> traversalStrategy = make_unique<IterativeInorder>();
    return traversalStrategy->inorder(root);
  }
};